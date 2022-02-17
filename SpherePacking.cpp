//Tennis balls in room calculator
// ReSharper disable once CppInconsistentNaming
// ReSharper disable CppClangTidyBugproneNarrowingConversions
// ReSharper disable CppClangTidyClangDiagnosticFloatConversion
#define _USE_MATH_DEFINES  // NOLINT(clang-diagnostic-reserved-macro-identifier, bugprone-reserved-identifier)
#include <cmath>
#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <cstring>
#include <functional>

using namespace std;

//Centimeter to Inches
long double cm_to_in(const long double cm)
{
    const long double in = cm/2.54;
    return in;
}

//const and Formulas
// tennisball diameter in cm 6.69925
constexpr long double diameter_tb_cm = 4;
constexpr long double radius_tb_cm = diameter_tb_cm / 2;
// Modifiers\const numbers
long double x_mod;
long double y_mod;
//Testing my programming knowledge because yeah.. there is no start stop step range function
vector<long double> range(long double start, const long double stop, const long double step)
{
    vector<long double> vector_list;
    while(start <= stop)
    {
        vector_list.push_back(start);
        start += step;
    }
    return vector_list;
}

/*-----Switch-Case-Room-Question------------------------------------------
int interrogation()
{
    char choice;
    basic_regex<char> regex;
    cout <<
        "Enter one of the following options:\n1:) You have more than one cube/cuboid room \n2:) End Program \nWe await your answer(type 1 or 2):: "
        << endl;
    cin >> choice;
    cin.clear();
    if (choice == '1' || choice == '2')
    {
        switch (choice)
        {
        case '1':
            cout << string(100, '\n') << endl;
            cout << "How many rectangles do you have?" << endl;
            
            break;
        case '2':
            cout << string(100, '\n') << endl;
            cout << "Option 2 Works" << endl;
            break;
        default:
            cout << "Invalid Option" << endl;
        }
    }
    else
    {
        cout << "Invalid Option Please Try Again" << endl;
        interrogation();
    }
    
    return 0;
}
*/

//-----------------------------Main-Function------------------------------
int main()
{
    // Size of Room in CM
    constexpr long double box_length_cm = 342.9;
    constexpr long double box_width_cm = 355.6;
    constexpr long double box_height_cm = 271.78;
    int num_of_balls = 0;
    // Get 3 dimensional location of each sphere
    const vector<long double> x_range = range(radius_tb_cm, box_length_cm + radius_tb_cm, 2*radius_tb_cm); // Range is homemade range function range(start,stop,step)
    const vector<long double> y_range = range(radius_tb_cm, box_width_cm + radius_tb_cm, 2*radius_tb_cm);
    const vector<long double> z_range = range(radius_tb_cm, box_height_cm + radius_tb_cm, sqrt(2)*radius_tb_cm);
    // Count the amount of spheres within the given rectangle/square
    for (const long double z : z_range)
    {
        for (const long double y : y_range)
        {
            for (const long double x : x_range)
            {
                // Type Conversion because total balls cant be half numbers
                const int filler_num = z / (sqrt(2)*radius_tb_cm);
                const int changed = fmod(filler_num, 2); // Modulo for long double numbers
                if(changed == 0)
                {
                    x_mod = 0;
                    y_mod = 0;
                }
                else
                {
                    x_mod = radius_tb_cm;
                    y_mod = radius_tb_cm;
                }
                const long double ball_pos_x = x + x_mod;
                const long double ball_pos_y = y + y_mod;
                const long double ball_pos_z = z;
                if ((ball_pos_x + radius_tb_cm <= box_length_cm) && (ball_pos_y + radius_tb_cm <= box_width_cm) && (ball_pos_z + radius_tb_cm <= box_height_cm))
                {
                    num_of_balls+=1;
                }
            }
        }
    }
    printf("%u : Balls in a L:%LF W:%LF H:%LF", num_of_balls, box_length_cm, box_width_cm, box_height_cm);
    return 0;
}
