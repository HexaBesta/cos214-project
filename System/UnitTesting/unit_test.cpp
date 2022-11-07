#include <limits.h>
#include <stdexcept>
#include "../Human.h"
#include "../Vehicle.h"
#include "../Country.h"
#include "../Platoon.h"
#include "../AirBranch.h"
#include "gtest/gtest.h"

namespace {

    // ---- Start of Unit Testing ---- //
    TEST(UnitTest, MoralTest) {
        Country country("Sandton", 22, NULL);
        Human human(100, 100, 10, &country, true);
        EXPECT_EQ(100, human.getMoral());
    }

    TEST(UnitTest, StateTest) {
        Country country("Sandton", 22, NULL);
        Human human(100, 100, 10, &country, true);

        string state = human.getState();

        if(state == "Fit") {
            SUCCEED();
        } else {
            FAIL();
        }
    }

    // ---- End of Unit Testing ---- //

    // ---- Start of Platoon Testing ---- //
    TEST(PlatoonTesting, getMoral) {
        vector<Unit*> vehicles;
        vector<Unit*> soldiers;
        Country country("Sandton", 22, NULL);

        soldiers.push_back(new Human(100, 100, 10, &country, true));
        vehicles.push_back(new Vehicle(100, 100, 10, &country, true));

        Platoon platoon = Platoon(soldiers, vehicles, 100, 100);

        platoon.setAccumlateMoral();
        EXPECT_EQ(100, platoon.getMoral());
    }

    TEST(PlatoonTesting, getHealth) {
        vector<Unit*> vehicles;
        vector<Unit*> soldiers;
        Country country("Sandton", 22, NULL);

        soldiers.push_back(new Human(100, 100, 10, &country, true));
        vehicles.push_back(new Vehicle(100, 100, 10, &country, true));

        Platoon platoon = Platoon(soldiers, vehicles, 100, 100);

        platoon.setAccumlateHealth();
        EXPECT_EQ(200, platoon.getHealth());
    }

    TEST(PlatoonTesting, getAmmo) {
        vector<Unit*> vehicles;
        vector<Unit*> soldiers;
        Country country("Sandton", 22, NULL);

        soldiers.push_back(new Human(100, 100, 10, &country, true));
        vehicles.push_back(new Vehicle(100, 100, 10, &country, true));

        Platoon platoon = Platoon(soldiers, vehicles, 100, 100);

        int totalAmmo = platoon.getAmmo()[0] + platoon.getAmmo()[1];

        EXPECT_EQ(200, totalAmmo);
    }

    TEST(PlatoonTesting, takeDamage) {
        vector<Unit*> vehicles;
        vector<Unit*> soldiers;
        Country country("Sandton", 22, NULL);

        soldiers.push_back(new Human(100, 100, 10, &country, true));
        vehicles.push_back(new Vehicle(100, 100, 10, &country, true));

        Platoon platoon = Platoon(soldiers, vehicles, 100, 100);

        EXPECT_EQ(1, platoon.takeDamage(50, true));
    }

    // ---- End of Platoon testing ---- //

    // ---- Start of Branch Test ---- //
    TEST(BranchTesting, getBranch) {
        AirBranch air(NULL);

        cout << air.getBranch() << endl;
    }
}