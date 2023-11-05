#include <gtest/gtest.h>
#include <chrono>

#include <APL/ParkingLot.h>
#include <APL/Exceptions.h>
#include <APL/Car.h>

TEST(ParkingLotTest, SetVehicleCapacity)
{
	APL::ParkingLot parkingLot;

	// Test setting a valid capacity
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 50);
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Car), 50);

	// Test setting a negative capacity
	EXPECT_THROW(parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, -10), APL::NegativeCapacityException);
}

TEST(ParkingLotTest, GetAvailableSlots)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 50);

	// Test getting available slots for a valid vehicle type
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Car), 50);

	// Test getting available slots for an invalid vehicle type
	EXPECT_THROW(parkingLot.getAvailableSlots(APL::VehicleType::Bus), APL::InvalidVehicleTypeException);
}

TEST(ParkingLotTest, ParkVehicle)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 1);

	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("ABC123", std::chrono::system_clock::now());
	APL::VehiclePtr car2 = carFactory.createVehicle("CBA321", std::chrono::system_clock::now());

	// Test successfully parking a vehicle
	EXPECT_NO_THROW(parkingLot.parkVehicle(car1));

	// Test parking when no slots are available
	EXPECT_THROW(parkingLot.parkVehicle(car2), APL::OutOfVehicleCapacityException);
}

TEST(ParkingLotTest, ReleaseVehicle)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 2);

	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("ABC123", std::chrono::system_clock::now());
	int ticket1 = parkingLot.parkVehicle(car1);

	// Test successfully releasing a vehicle
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket1), car1->calculateCharge());

	// Test releasing a vehicle with an invalid ticket
	EXPECT_THROW(parkingLot.releaseVehicle(ticket1+1), APL::InvalidTicketIDException);
}

TEST(ParkingLotTest, CalculateCharge)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 2);

	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("ABC123", std::chrono::system_clock::now());

	int ticket1 = parkingLot.parkVehicle(car1);

	// Test calculating the charge for a parked vehicle
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket1), car1->calculateCharge());

	// Test calculating the charge for an invalid ticket
	EXPECT_THROW(parkingLot.calculateCharge(999), APL::InvalidTicketIDException);
}