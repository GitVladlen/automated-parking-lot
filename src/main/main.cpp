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
	APL::ParkingLot parkingLot(10, 5, 2);  // 10 car slots, 5 motorcycle slots, and 2 bus slots

	// Vehicle enters the parking lot
	APL::VehiclePtr car1 = std::make_shared<APL::Car>("ABC123", std::chrono::system_clock::now() - std::chrono::hours(5));
	int ticket1 = parkingLot.parkVehicle(car1);

	// Another vehicle enters
	APL::VehiclePtr motorcycle1 = std::make_shared<APL::Motorcycle>("XYZ456", std::chrono::system_clock::now() - std::chrono::hours(2));
	int ticket2 = parkingLot.parkVehicle(motorcycle1);

	std::cout << "Available Car Slots: " << parkingLot.getAvailableCarSlots() << std::endl;
	std::cout << "Available Motorcycle Slots: " << parkingLot.getAvailableMotorcycleSlots() << std::endl;
	std::cout << "Available Bus Slots: " << parkingLot.getAvailableBusSlots() << std::endl;

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
	std::cout << "Available Car Slots: " << parkingLot.getAvailableCarSlots() << std::endl;
	std::cout << "Available Motorcycle Slots: " << parkingLot.getAvailableMotorcycleSlots() << std::endl;
	std::cout << "Available Bus Slots: " << parkingLot.getAvailableBusSlots() << std::endl;

	return 0;
}