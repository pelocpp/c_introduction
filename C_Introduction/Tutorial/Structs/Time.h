// ===========================================================================
// Time.h // Uhrzeit
// ===========================================================================

#pragma once

// types
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

// function prototypes
void initTime(struct Time* time, int hours, int minutes, int seconds);
// void initTime(struct Time time, int hours, int minutes, int seconds);
void printTime(struct Time* time);
// void printTime(struct Time time);

// ===========================================================================
// End-of-File
// ===========================================================================
