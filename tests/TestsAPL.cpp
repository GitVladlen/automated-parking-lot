#include <gtest/gtest.h>
#include <chrono>

#include <APL/Exceptions.h>
#include <APL/ParkingLot.h>
#include <APL/Car.h>
#include <APL/Motorcycle.h>
#include <APL/Bus.h>

TEST(ParkingLotTest, SetVehicleCapacity)
{
	APL::ParkingLot parkingLot;

	// Test setting a valid capacity
	EXPECT_NO_THROW(parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 50));
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Car), 50);

	// Test setting a negative capacity
	EXPECT_THROW(parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, -10), APL::NegativeCapacityException);
}

TEST(ParkingLotTest, GetAvailableSlotsCar)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 50);

	// Test getting available slots for a valid vehicle type
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Car), 50);

	// Test getting available slots for an invalid vehicle type
	EXPECT_THROW(parkingLot.getAvailableSlots(APL::VehicleType::Bus), APL::InvalidVehicleTypeException);
}

TEST(ParkingLotTest, GetAvailableSlotsMotorcycle)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 40);

	// Test getting available slots for a valid vehicle type
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle), 40);

	// Test getting available slots for an invalid vehicle type
	EXPECT_THROW(parkingLot.getAvailableSlots(APL::VehicleType::Car), APL::InvalidVehicleTypeException);
}

TEST(ParkingLotTest, GetAvailableSlots)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 30);

	// Test getting available slots for a valid vehicle type
	EXPECT_EQ(parkingLot.getAvailableSlots(APL::VehicleType::Bus), 30);

	// Test getting available slots for an invalid vehicle type
	EXPECT_THROW(parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle), APL::InvalidVehicleTypeException);
}

TEST(ParkingLotTest, ParkVehicle)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 1);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 1);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 1);

	// Cars
	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("CCC123", 2);
	APL::VehiclePtr car2 = carFactory.createVehicle("CCC321", 3);

	// Test successfully parking a vehicle
	EXPECT_NO_THROW(parkingLot.parkVehicle(car1));

	// Test parking when no slots are available
	EXPECT_THROW(parkingLot.parkVehicle(car2), APL::OutOfVehicleCapacityException);

	// Motorcycles
	APL::MotorcycleFactory motorcycleFactory;

	APL::VehiclePtr mc1 = motorcycleFactory.createVehicle("MMM123", 2);
	APL::VehiclePtr mc2 = motorcycleFactory.createVehicle("MMM321", 3);

	// Test successfully parking a vehicle
	EXPECT_NO_THROW(parkingLot.parkVehicle(mc1));

	// Test parking when no slots are available
	EXPECT_THROW(parkingLot.parkVehicle(mc2), APL::OutOfVehicleCapacityException);

	// Buses
	APL::BusFactory busFactory;

	APL::VehiclePtr bus1 = busFactory.createVehicle("BBB123", 2);
	APL::VehiclePtr bus2 = busFactory.createVehicle("BBB321", 3);

	// Test successfully parking a vehicle
	EXPECT_NO_THROW(parkingLot.parkVehicle(bus1));

	// Test parking when no slots are available
	EXPECT_THROW(parkingLot.parkVehicle(bus2), APL::OutOfVehicleCapacityException);
}

TEST(ParkingLotTest, ReleaseVehicle)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 3);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 3);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 3);

	// Cars: $2 for the first hour, then $1 for each subsequent hour.
	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("CCC111", 1);
	APL::VehiclePtr car2 = carFactory.createVehicle("CCC222", 2);
	APL::VehiclePtr car3 = carFactory.createVehicle("CCC333", 3);

	int ticket1 = parkingLot.parkVehicle(car1);
	int ticket2 = parkingLot.parkVehicle(car2);
	int ticket3 = parkingLot.parkVehicle(car3);

	// Test for releasing parked cars
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket1), 2.0f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket2), 3.0f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket3), 4.0f);

	// Motorcycles: $1 for the first hour, then $0.50 for each subsequent hour.
	APL::MotorcycleFactory motorcycleFactory;

	APL::VehiclePtr mc1 = motorcycleFactory.createVehicle("MMM111", 1);
	APL::VehiclePtr mc2 = motorcycleFactory.createVehicle("MMM222", 2);
	APL::VehiclePtr mc3 = motorcycleFactory.createVehicle("MMM333", 3);

	int ticket4 = parkingLot.parkVehicle(mc1);
	int ticket5 = parkingLot.parkVehicle(mc2);
	int ticket6 = parkingLot.parkVehicle(mc3);

	// Test for releasing parked motorcycles
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket4), 1.0f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket5), 1.5f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket6), 2.0f);

	// Buses: $5 for the first hour, then $3 for each subsequent hour.
	APL::BusFactory busFactory;

	APL::VehiclePtr bus1 = busFactory.createVehicle("BBB111", 1);
	APL::VehiclePtr bus2 = busFactory.createVehicle("BBB222", 2);
	APL::VehiclePtr bus3 = busFactory.createVehicle("BBB333", 3);

	int ticket7 = parkingLot.parkVehicle(bus1);
	int ticket8 = parkingLot.parkVehicle(bus2);
	int ticket9 = parkingLot.parkVehicle(bus3);

	// Test for releasing parked buses
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket7), 5.0f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket8), 8.0f);
	EXPECT_FLOAT_EQ(parkingLot.releaseVehicle(ticket9), 11.0f);

	// Test releasing a vehicle with an invalid ticket
	EXPECT_THROW(parkingLot.releaseVehicle(999), APL::InvalidTicketIDException);
}

TEST(ParkingLotTest, CalculateCharge)
{
	APL::ParkingLot parkingLot;
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 3);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 3);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 3);

	// Cars: $2 for the first hour, then $1 for each subsequent hour.
	APL::CarFactory carFactory;

	APL::VehiclePtr car1 = carFactory.createVehicle("CCC111", 1);
	APL::VehiclePtr car2 = carFactory.createVehicle("CCC222", 2);
	APL::VehiclePtr car3 = carFactory.createVehicle("CCC333", 3);

	int ticket1 = parkingLot.parkVehicle(car1);
	int ticket2 = parkingLot.parkVehicle(car2);
	int ticket3 = parkingLot.parkVehicle(car3);

	// Test calculating the charge for a parked cars
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket1), 2.0f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket2), 3.0f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket3), 4.0f);

	// Motorcycles: $1 for the first hour, then $0.50 for each subsequent hour.
	APL::MotorcycleFactory motorcycleFactory;

	APL::VehiclePtr mc1 = motorcycleFactory.createVehicle("MMM111", 1);
	APL::VehiclePtr mc2 = motorcycleFactory.createVehicle("MMM222", 2);
	APL::VehiclePtr mc3 = motorcycleFactory.createVehicle("MMM333", 3);

	int ticket4 = parkingLot.parkVehicle(mc1);
	int ticket5 = parkingLot.parkVehicle(mc2);
	int ticket6 = parkingLot.parkVehicle(mc3);

	// Test calculating the charge for a parked motorcycles
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket4), 1.0f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket5), 1.5f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket6), 2.0f);

	// Buses: $5 for the first hour, then $3 for each subsequent hour.
	APL::BusFactory busFactory;

	APL::VehiclePtr bus1 = busFactory.createVehicle("BBB111", 1);
	APL::VehiclePtr bus2 = busFactory.createVehicle("BBB222", 2);
	APL::VehiclePtr bus3 = busFactory.createVehicle("BBB333", 3);

	int ticket7 = parkingLot.parkVehicle(bus1);
	int ticket8 = parkingLot.parkVehicle(bus2);
	int ticket9 = parkingLot.parkVehicle(bus3);

	// Test calculating the charge for a parked buses
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket7), 5.0f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket8), 8.0f);
	EXPECT_FLOAT_EQ(parkingLot.calculateCharge(ticket9), 11.0f);

	// Test calculating the charge for an invalid ticket
	EXPECT_THROW(parkingLot.calculateCharge(999), APL::InvalidTicketIDException);
}