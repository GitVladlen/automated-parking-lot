#include <APL/Logger.h>

#include "AutomatedParkingLotApp.h"

int main()
{
    try
    {
        App::AutomatedParkingLotApp app;
        int result = app.run();
        return result;
    }
    catch (const std::exception& e)
    {
        LOG_ERROR_FMT("An error occurred: %s", e.what());
        return 1; // Return a non-zero value to indicate an error.
    }
    catch (...)
    {
        LOG_ERROR("An unknown error occurred.",);
        return 1; // Return a non-zero value to indicate an error.
    }
}
