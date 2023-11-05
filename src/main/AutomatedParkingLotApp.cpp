#include <iostream>
#include <algorithm>
#include <string>

#include "AutomatedParkingLotApp.h"

#include <APL/Logger.h>
#include <APL/Car.h>
#include <APL/Motorcycle.h>
#include <APL/Bus.h>

namespace App
{
	AutomatedParkingLotApp::AutomatedParkingLotApp()
	{
        // Set vehicle factories by its type
		m_vehicleFactories[APL::VehicleType::Car] = std::make_shared<APL::CarFactory>();
		m_vehicleFactories[APL::VehicleType::Motorcycle] = std::make_shared<APL::MotorcycleFactory>();
		m_vehicleFactories[APL::VehicleType::Bus] = std::make_shared <APL::BusFactory>();

        // Set the initial capacity for different vehicle types
        m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Car, 5);
        m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Motorcycle, 2);
        m_parkingLot.setVehicleTypeCapacity(APL::VehicleType::Bus, 1);
	}

	int AutomatedParkingLotApp::run()
	{
        // Create a mapping from input strings to corresponding VehicleType enum values
        std::unordered_map<std::string, APL::VehicleType> vehicleTypeMap = {
            {"c", APL::VehicleType::Car},
            {"car", APL::VehicleType::Car},
            {"m", APL::VehicleType::Motorcycle},
            {"motorcycle", APL::VehicleType::Motorcycle},
            {"b", APL::VehicleType::Bus},
            {"bus", APL::VehicleType::Bus}
        };

        while (true) {
            std::cout << "Menu:\n";
            std::cout << "1. Check available slots for Car\n";
            std::cout << "2. Check available slots for Motorcycle\n";
            std::cout << "3. Check available slots for Bus\n";
            std::cout << "4. Park a Vehicle\n";
            std::cout << "5. Release a Vehicle\n";
            std::cout << "6. Exit\n";
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
            case 1: {
                // Query available slots for Car
                try 
                {
                    int availableSlots = m_parkingLot.getAvailableSlots(APL::VehicleType::Car);
                    LOG_INFO_FMT("Available Car slots: %i", availableSlots);
                }
                catch (const std::exception& e) 
                {
                    LOG_ERROR_FMT("Error: %s", e.what());
                }
                break;
            }
            case 2: {
                // Query available slots for Motorcycle
                try 
                {
                    int availableSlots = m_parkingLot.getAvailableSlots(APL::VehicleType::Motorcycle);
                    LOG_INFO_FMT("Available Motorcycle slots: %i", availableSlots);
                }
                catch (const std::exception& e)
                {
                    LOG_ERROR_FMT("Error: %s", e.what());
                }
                break;
            }
            case 3: {
                // Query available slots for Bus
                try {
                    int availableSlots = m_parkingLot.getAvailableSlots(APL::VehicleType::Bus);
                    LOG_INFO_FMT("Available Bus slots: %i", availableSlots);
                }
                catch (const std::exception& e) {
                    LOG_ERROR_FMT("Error: %s", e.what());
                }
                break;
            }
            case 4: {
                // Park a vehicle
                std::cout << "Enter vehicle type (Car/Motorcycle/Bus or C/M/B): ";
                std::string vehicleTypeStr;
                std::cin >> vehicleTypeStr;

                std::transform(vehicleTypeStr.begin(), vehicleTypeStr.end(), vehicleTypeStr.begin(),
                    [](unsigned char c) { return std::tolower(c); });

                APL::VehicleType vehicleType;

                // Check if the input is in the map
                if (vehicleTypeMap.find(vehicleTypeStr) != vehicleTypeMap.end()) {
                    vehicleType = vehicleTypeMap[vehicleTypeStr];
                }
                else {
                    LOG_ERROR("Invalid vehicle type. Please enter C, Car, M, Motorcycle, B, or Bus.");
                    continue;
                }

                std::cout << "Vehicle type: " << APL::vehicleTypeToString(vehicleType) << std::endl;

                std::cout << "Enter license number: ";
                std::string licenseNumber;
                std::cin >> licenseNumber;

                // Record the entering timestamp
                auto enteringTime = std::chrono::system_clock::now();

                try {
                    APL::VehiclePtr newVehicle = createVehicle(vehicleType, licenseNumber, enteringTime);
                    int ticketID = m_parkingLot.parkVehicle(newVehicle);
                    LOG_INFO_FMT("Vehicle parked with ticket ID: %i", ticketID);
                }
                catch (const std::exception& e) {
                    LOG_ERROR_FMT("Error: %s", e.what());
                }
                break;
            }
            case 5: {
                // Release a vehicle
                std::cout << "Enter ticket ID for the vehicle to release: ";
                int ticketToRelease;
                std::cin >> ticketToRelease;
                try {
                    float charge = m_parkingLot.releaseVehicle(ticketToRelease);
                    LOG_INFO_FMT("Vehicle released with charge: $%.2f", charge);
                }
                catch (const std::exception& e) {
                    LOG_ERROR_FMT("Error: %s", e.what());
                }
                break;
            }
            case 6: {
                // Exit the program
                std::cout << "Exiting program.\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please select a valid option.\n";
                break;
            }
            }
        }

		return 0;
	}

	APL::VehiclePtr AutomatedParkingLotApp::createVehicle(APL::VehicleType _vehicleType, const std::string& _licensePlate, const APL::Timestamp& _parkingTimestamp)
	{
		// Check if the requested vehicle type exists in the factories map.
		auto factoryIt = m_vehicleFactories.find(_vehicleType);
		if (factoryIt == m_vehicleFactories.end()) {
			// Handle the case where the vehicle type is not found.
			throw std::runtime_error("No factory found for vehicle type " + APL::vehicleTypeToString(_vehicleType));
		}

		// Create the vehicle using the corresponding factory.
		APL::VehiclePtr vehicle = factoryIt->second->createVehicle(_licensePlate, _parkingTimestamp);

		return vehicle;
	}
}