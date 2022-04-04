#include "header.h"

bool string_binary_search(string filename, int line, string search_thing)
{

}

int binarySearch(string arr[], string key, int size)
{

}

vector<string> list_of_files(string folder)
{
    vector<string> names;
    string search_path = folder + "/*.*";
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
    if(hFind != INVALID_HANDLE_VALUE) {
        do {

            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return names;
}

bool check_file_if_exits(string filename, string folderName)
{
    vector<string> filenames = list_of_files(folderName);

    for(auto E : filenames)
    {
        if(E==filename)
            return true;
    }

    return false;
}
