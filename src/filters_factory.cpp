#include "filters.hpp"

Filters* createFiltersOpenCV();
// Declare your implementation here
// Filters* createFiltersYourName();
Filters* createFiltersMoskalenko();

Filters* createFilters(FILTERS_IMPLEMENTATIONS impl)
{
    switch (impl) {
        case OPENCV:
            return createFiltersOpenCV();
        // Add case for your implementation
        // case YOUR_NAME:
        //     return createFiltersYourName();
		case Moskalenko:
            return createFiltersMoskalenko();
        default:
            return 0;
    }
}
