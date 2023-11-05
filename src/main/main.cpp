#include <iostream>
#include <chrono>

#include <APL/ParkingLot.h>
#include <APL/Car.h>
#include <APL/Motorcycle.h>
#include <APL/Bus.h>

int main()
{
	std::cout << "Automated Parking Lot!" << std::endl;

	// TODO: Unit tests

	// Create a parking lot
	APL::ParkingLot parkingLot;  

	// 10 car slots, 5 motorcycle slots, and 2 bus slots
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 10);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 5);
	parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 2);

	// Vehicle enters the parking lot
	APL::VehiclePtr car1 = std::make_shared<APL::Car>("ABC123", std::chrono::system_clock::now() - std::chrono::hours(5));
	int ticket1 = parkingLot.parkVehicle(car1);

	// Another vehicle enters
	APL::VehiclePtr motorcycle1 = std::make_shared<APL::Motorcycle>("XYZ456", std::chrono::system_clock::now() - std::chrono::hours(2));
	int ticket2 = parkingLot.parkVehicle(motorcycle1);

	std::cout << "Available Car Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Car) << std::endl;
	std::cout << "Available Motorcycle Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle) << std::endl;
	std::cout << "Available Bus Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Bus) << std::endl;

	// Simulate some time passing
	// ...

	// Vehicle exits
	double car1Charge = parkingLot.releaseVehicle(ticket1);

	// Another vehicle exits
	double motorcycle1Charge = parkingLot.releaseVehicle(ticket2);

	// Print charges and logs
	std::cout << "Car1 Charge: $" << car1Charge << std::endl;
	std::cout << "Motorcycle1 Charge: $" << motorcycle1Charge << std::endl;

	// Query available slots
	std::cout << "Available Car Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Car) << std::endl;
	std::cout << "Available Motorcycle Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle) << std::endl;
	std::cout << "Available Bus Slots: " << parkingLot.getAvailableSlots(APL::VehicleType::Bus) << std::endl;

	return 0;
}