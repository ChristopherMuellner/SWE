#include "../Header Files/TimeSpan.hpp"


TimeSpan::TimeSpan()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
    milliseconds = 0;
}


TimeSpan::TimeSpan(const TimeSpan& other)
{
    this-> hours = other.hours;
    this-> minutes = other.minutes;
    this-> seconds = other.seconds;
    this-> milliseconds = other.milliseconds;
}


TimeSpan::TimeSpan(int hours, int minutes, int seconds, int milliseconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
    this->milliseconds = milliseconds;
}


void TimeSpan::addHours(int hours)
{
    this->hours += hours;

    if (this->hours < 0)
    {
        this->hours = 0;
    }
}


void TimeSpan::addMinutes(int minutes)
{
    int totalMinutes = this->hours * 60 + this->minutes + minutes;

    this->hours = (totalMinutes / 60) % 24;
    this->minutes = totalMinutes % 60;
}


void TimeSpan::addSeconds(int seconds)
{
    int totalSeconds = this->hours * 3600 + this->minutes * 60 + this->seconds + seconds;

    this->hours = (totalSeconds / 3600) % 24;
    this->minutes = (totalSeconds / 60) % 60;
    this->seconds = totalSeconds % 60;
}


void TimeSpan::addMilliseconds(int milliseconds)
{
    int totalMilliseconds = this->hours * 3600000 + this->minutes * 60000 + this->seconds * 1000 + this->milliseconds + milliseconds;

    this->hours = (totalMilliseconds / 3600000) % 24;
    this->minutes = (totalMilliseconds / 60000) % 60;
    this->seconds = (totalMilliseconds / 1000) % 60;
    this->milliseconds = totalMilliseconds % 1000;
}


string TimeSpan::toString() const
{
    string formattedString;

    formattedString += '0' + (this->hours / 10);
    formattedString += '0' + (this->hours % 10);
    formattedString += ":";

    formattedString += '0' + (this->minutes / 10);
    formattedString += '0' + (this->minutes % 10);
    formattedString += ":";

    formattedString += '0' + (this->seconds / 10);
    formattedString += '0' + (this->seconds % 10);
    formattedString += ",";

    formattedString += '0' + (this->milliseconds / 100);
    formattedString += '0' + ((this->milliseconds / 10) % 10);
    formattedString += '0' + (this->milliseconds % 10);

    return formattedString;
}


TimeSpan TimeSpan::operator- (const TimeSpan& other) const
{
    TimeSpan difference;

    difference.addHours(this->hours - other.hours);
    difference.addMinutes(this->minutes - other.minutes);
    difference.addSeconds(this->seconds - other.seconds);
    difference.addMilliseconds(this->milliseconds - other.milliseconds);

    return difference;
}


TimeSpan TimeSpan::operator+ (const TimeSpan& other) const
{
    TimeSpan sum;

    sum.addHours(this->hours + other.hours);
    sum.addMinutes(this->minutes + other.minutes);
    sum.addSeconds(this->seconds + other.seconds);
    sum.addMilliseconds(this->milliseconds + other.milliseconds);

    return sum;
}


TimeSpan TimeSpan::operator* (float multiplier) const
{
    double totalMilliseconds = (double(this->hours) * 3600 * 1000) + (double(this->minutes) * 60 * 1000) + (double(this->seconds) * 1000) + double(this->milliseconds);

    totalMilliseconds *= multiplier;

    TimeSpan result;
    result.hours = (int)(totalMilliseconds / (3600 * 1000));
    totalMilliseconds -= result.hours * (3600 * 1000);
    result.minutes = (int)(totalMilliseconds / (60 * 1000));
    totalMilliseconds -= result.minutes * (60 * 1000);
    result.seconds = (int)(totalMilliseconds / 1000);
    result.milliseconds = (int)totalMilliseconds % 1000;

    return result;
}


int TimeSpan::getHours() const
{
    return hours;
}


int TimeSpan::getMinutes() const
{
    return minutes;
}


int TimeSpan::getSeconds() const
{
    return seconds;
}


int TimeSpan::getMilliseconds() const
{
    return milliseconds;
}


int TimeSpan::getTotalMilliseconds() const
{
    return (this->hours * 3600 * 1000) + (this->minutes * 60 * 1000) + (this->seconds * 1000 + this->milliseconds);
}