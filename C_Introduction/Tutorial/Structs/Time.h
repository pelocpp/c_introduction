// ===========================================================================
// Time.h // Uhrzeit
// ===========================================================================

#pragma once

// types
struct time
{
    int hours;
    int minutes;
    int seconds;
};

typedef struct time Time;

// function prototypes
void initTime(Time* time, int hours, int minutes, int seconds);
void printTime(Time* time);

// void initTime(Time time, int hours, int minutes, int seconds);
// void printTime(Time time);

// ===========================================================================
// End-of-File
// ===========================================================================
