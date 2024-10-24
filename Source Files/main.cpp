/*TODO: Fix Abzug von Stunden, Minuten, Sekunden*/

#include "../Header Files/TimeSpan.hpp"

int main()
{


    TimeSpan duration;
    duration.addHours(-6);
    duration.addMinutes(100);
    duration.addSeconds(-3);
    duration.addMilliseconds(55);

    cout << duration.toString() << endl; // prints 07:39:57,055



    /*----------------------------------------------------------------------------------------------------------------*/


    TimeSpan duration1(1, 35, 22, 87);
    TimeSpan duration2(0, 44, 51, 3);

    TimeSpan difference = duration1 - duration2;
    cout << difference.toString() << endl; // prints 00:50:31,084


    /*----------------------------------------------------------------------------------------------------------------*/




    TimeSpan sum = duration1 + duration2;
    cout << sum.toString() << endl; // prints 02:20:13,090


    /*----------------------------------------------------------------------------------------------------------------*/


    TimeSpan duration5(2, 14, 55, 06);
    float multiplicator = 1.5f;

    TimeSpan result = duration5 * multiplicator;
    cout << result.toString() << endl; // prints 03:22:22,509


    /*----------------------------------------------------------------------------------------------------------------*/


    cout << endl;
    cout << "Stunden: " << duration5.getHours() << endl;
    cout << "Minuten: " << duration5.getMinutes() << endl;
    cout << "Seconds: " << duration5.getSeconds() << endl;
    cout << "Millisekunden: " << duration5.getMilliseconds() << endl;
    cout << "Gesamtmillisekunden: " << duration5.getTotalMilliseconds() << endl;


}