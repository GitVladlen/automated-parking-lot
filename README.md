# Automated Parking Lot Application

The Automated Parking Lot (APL) application, named `AutomatedParkingLotApp`, is designed to manage a parking lot with support for various vehicle types. It allows you to check available parking slots, park vehicles, and release vehicles with associated charges. The application provides a command-line interface for user interactions.

## Assumptions

The provided application is a simplified representation of a parking lot management system and may not cover all real-life parking lot complexities. The key assumptions include:

- **Charge Calculation:** The application uses a simple mechanism to calculate charges based on parking duration for different vehicle types. In a real-world scenario, it may involve more complex pricing models, different tariffs for peak hours, or special event pricing.

- **Parking Lot Capacity:** The parking lot has a limited capacity for each vehicle type, which is set at initialization. Real-world parking lots might have dynamic capacity management and tracking based on current occupancy.

- **Error Handling:** The application demonstrates the use of exceptions to handle errors, such as exceeding vehicle capacity or invalid inputs.

## High-Level Design Choices

The application follows several high-level design choices to structure and manage the parking lot effectively. These choices include:

- **Vehicle Hierarchy:** The application uses a hierarchy of vehicle classes (Car, Motorcycle, Bus) derived from a base Vehicle class. This hierarchy allows for extensibility, making it easier to add new vehicle types with specific behaviors in the future.

- **Factory Pattern:** To create vehicles, the application uses a VehicleFactory interface. This design choice allows for the creation of different vehicle types without exposing the details of how each type is constructed.

- **ParkingLot Class:** The ParkingLot class manages the parking lot's state, including parked vehicles, vehicle type capacities, and ticket-to-vehicle mapping. It uses mutexes for thread safety.

- **Logger:** The application employs a Logger class to log various events, such as parking, releasing vehicles, and errors. It creates a `data.log` file and flushes it after application closure. This design choice provides a way to record activities and errors for monitoring and debugging.

- **AutomatedParkingLotApp:** This class acts as the application's main entry point and handles user interaction through the console. It allows users to check available parking slots, park vehicles, release vehicles, and exit the application.

- **Exception Handling:** The application uses custom exceptions like NegativeCapacityException and InvalidVehicleTypeException to handle errors gracefully. This approach makes it easier to identify and address issues.

- **CMake and Visual Studio:** The build system is set up with CMake, and the application is designed to work with Visual Studio 2019 for ease of development.

- **Google Test Integration:** The application includes a TestsAPL project that uses Google Test for unit testing. This ensures the reliability and correctness of the code.

## Getting Started

### Prerequisites
Before you begin, make sure you have the following installed:
- [CMake](https://cmake.org/download/#latest) (added to your system PATH)
- Visual Studio 2019 with C++ Desktop Development Pack

### Build and Run

Follow these steps to build and run the Automated Parking Lot (APL) application:

1. Run the `generate_project.bat` script. This script will generate a Visual Studio solution in the 'build' folder, and it also triggers the fetching of the Google Test library, which is used for running unit tests.

2. Open the `build/AutomatedParkingLot.sln` solution in Visual Studio 2019.

3. Build the solution within Visual Studio.

4. Run the application.

### Troubleshooting
- If you encounter any build errors or issues, check the build logs or refer to the project documentation for troubleshooting instructions.

### APL Core Library

The core classes of the Automated Parking Lot (APL) application are organized into a separate library named `APL`. This library includes essential classes for managing parking lot and vehicles. It is linked to the `AutomatedParkingLot` project to provide the necessary functionality to the `AutomatedParkingLotApp`.

### Logger

The APL application uses a logger that creates a 'data.log' file. The logger records information, warnings, and errors during the application's runtime. It fully updates (flushes) the log file when the application is closed. You can review this log file for a history of events and messages related to the application's operations.

## Running Tests

The Automated Parking Lot (APL) project includes unit tests using Google Test. You can run these tests to ensure that the application functions as expected. Follow these steps to run the tests:

1. Open the `TestsAPL` project within the `AutomatedParkingLot` solution in Visual Studio 2019.

2. Build the `TestsAPL` project within Visual Studio.

3. Run the test executable, which is typically named `TestsAPL.exe.` This executable is generated within the `build/tests/Debug` folder.

4. Review the test results in the console or test runner provided by Google Test.

If the tests pass without any failures, it indicates that the application is working correctly. In case of test failures, the output will provide details about the issues.

### Test Coverage

The project's unit tests cover various aspects of the application, including vehicle creation, parking, and charging calculations. You can use these tests to ensure the correctness and reliability of the APL application.

### Troubleshooting

If you encounter any test-related issues or failures, refer to the test output for error messages and consult the project documentation for troubleshooting tips.

For more detailed information about the Automated Parking Lot (APL) project's tests and coverage, please refer to the project's test documentation.


