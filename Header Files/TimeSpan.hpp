#ifndef TIMESPAN_TIMESPAN_HPP
#define TIMESPAN_TIMESPAN_HPP

#include <iostream>

using namespace std;


class TimeSpan
{
    public:
        TimeSpan();
        TimeSpan(int hours, int minutes, int seconds, int milliseconds);
        TimeSpan(const TimeSpan& other);

        TimeSpan operator+ (const TimeSpan& other) const;
        TimeSpan operator- (const TimeSpan& other) const;
        TimeSpan operator* (float multiplier) const;

        void addHours(int x);
        void addMinutes(int x);
        void addSeconds (int x);
        void addMilliseconds(int x);

        [[nodiscard]] int getHours() const;
        [[nodiscard]] int getMinutes() const;
        [[nodiscard]] int getSeconds() const;
        [[nodiscard]] int getMilliseconds() const;
        [[nodiscard]] int getTotalMilliseconds() const;

        [[nodiscard]] string toString() const;


    private:
        int hours;
        int minutes;
        int seconds;
        int milliseconds;
};


#endif //TIMESPAN_TIMESPAN_HPP