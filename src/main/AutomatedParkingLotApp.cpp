#include <iostream>

#include "AutomatedParkingLotApp.h"

#include <APL/Logger.h>
#include <APL/Car.h>
#include <APL/Motorcycle.h>
#include <APL/Bus.h>

namespace App
{
	AutomatedParkingLotApp::AutomatedParkingLotApp()
	{
		m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 50);
		m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 20);
		m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 10);
	}

	int AutomatedParkingLotApp::run()
	{
		LOG_INFO("Automated Parking Lot!");

		// Create a parking lot
		APL::ParkingLot parkingLot;

		// 10 car slots, 5 motorcycle slots, and 2 bus slots
		parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 10);
		parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 5);
		parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 2);

		// Create vehicle factories
		APL::CarFactory carFactory;
		APL::MotorcycleFactory motorcycleFactory;
		APL::BusFactory busFactory;

		// Vehicle enters the parking lot
		APL::VehiclePtr car1 = carFactory.createVehicle("ABC123", std::chrono::system_clock::now() - std::chrono::hours(5));
		int ticket1 = parkingLot.parkVehicle(car1);

		// Another vehicle enters
		APL::VehiclePtr motorcycle1 = motorcycleFactory.createVehicle("CBA456", std::chrono::system_clock::now() - std::chrono::hours(2));
		int ticket2 = parkingLot.parkVehicle(motorcycle1);

		// Another vehicle enters
		APL::VehiclePtr bus1 = busFactory.createVehicle("WER768", std::chrono::system_clock::now() - std::chrono::hours(2));
		int ticket3 = parkingLot.parkVehicle(bus1);

		LOG_INFO_FMT("Available Car Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Car));
		LOG_INFO_FMT("Available Motorcycle Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle));
		LOG_INFO_FMT("Available Bus Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Bus));

		// Simulate some time passing
		// ...

		// Vehicle exits
		double car1Charge = parkingLot.releaseVehicle(ticket1);

		// Another vehicle exits
		double motorcycle1Charge = parkingLot.releaseVehicle(ticket2);

		// Another vehicle exits
		double bus1Charge = parkingLot.releaseVehicle(ticket3);

		// Print charges and logs
		LOG_INFO_FMT("Car1 Charge: $%.2f", car1Charge);
		LOG_INFO_FMT("Motorcycle1 Charge: $%.2f", motorcycle1Charge);
		LOG_INFO_FMT("Bus1 Charge: $%.2f", bus1Charge);

		// Query available slots
		LOG_INFO_FMT("Available Car Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Car));
		LOG_INFO_FMT("Available Motorcycle Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle));
		LOG_INFO_FMT("Available Bus Slots: %i", parkingLot.getAvailableSlots(APL::VehicleType::Bus));

		return 0;
	}
}