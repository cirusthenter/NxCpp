#pragma once

bool equal_to_6th_place(double a, double b)
{
    // This has to be updated
    int x1 = (a * 1048576); // 1048576 = 2^20
    int x2 = (b * 1048576); // 1048576 = 2^20
    return x1 == x2;
}
