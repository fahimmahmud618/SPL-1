#include "header.h"

bool string_binary_search(string filename, int line, string search_thing)
{

}

int binarySearch(string arr[], string key, int size)
{

}
int binarySearch(string arr[], string key,int n)
    {
        int l = 0 ;
        int r = n - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;

        int res = -1000;

        if (key == (arr[m]))
            res = 0;

            if (res == 0)
                return m;

            // If x greater, ignore left half
            if (key > (arr[m]))
                l = m + 1;

            else
                r = m - 1;
        }

        return -1;
    }
