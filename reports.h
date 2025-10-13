/*Program header*/

#ifndef REPORTS_H
#define REPORTS_H

#include "bookType.h"

void reports (bool &keepReportsMenuActive);

void repListing  (bool &keepReportsMenuActive, bool &keepRepListingMenuActive);

void repWholesale  (bool &keepReportsMenuActive, bool &keepRepWholesaleMenuActive);

void repRetail  (bool &keepReportsMenuActive, bool &keepRepRetailMenuActive);

void repQty  (bool &keepReportsMenuActive, bool &keepRepQtyMenuActive);

void repCost  (bool &keepReportsMenuActive, bool &keepRepCostMenuActive);

void repAge  (bool &keepReportsMenuActive, bool &keepRepAgeMenuActive);
#endif
