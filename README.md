# Automated Parking Lot Application

The Automated Parking Lot (APL) application, named `AutomatedParkingLotApp`, is designed to manage a parking lot with support for various vehicle types. It allows you to check available parking slots, park vehicles, and release vehicles with associated charges. The application provides a command-line interface for user interactions.

## Getting Started

### Prerequisites
Before you begin, make sure you have the following installed:
- [CMake](https://cmake.org/download/#latest) (added to your system PATH)
- Visual Studio 2019 with C++ Desktop Development Pack

### Build and Run
Follow these steps to build and run the Automated Parking Lot (APL) application:

1. Run the `generate_project.bat` script to generate a Visual Studio solution in the 'build' folder. This script will create the necessary project files.

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


