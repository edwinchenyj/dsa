#include<vector>
#include<iostream>
#include<cstdlib>

using namespace std;

int partition(vector<int>& v, int left, int right)
{
    int pivot = v[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (v[j] <= pivot) {
            swap(v[i], v[j]);
            ++i;
        }
    }
    swap(v[i], v[right]);
    return i;
}

void quicksort(vector<int>& v, int left, int right)
{
    if(left < right) {
        int pivot = partition(v, left, right);
        quicksort(v, left, pivot - 1);
        quicksort(v, pivot + 1, right);
    }
}

int quickselect(vector<int>& v, int left, int right, int k)
{
    if (left == right) {
        return v[left];
    }
    int pivot = partition(v, left, right);
    if (k == pivot) {
        return v[k];
    } else if (k < pivot) {
        return quickselect(v, left, pivot - 1, k);
    } else {
        return quickselect(v, pivot + 1, right, k);
    }
}

int main(int argc, char* argv[])
{
    srand((unsigned) time(NULL));
    vector<int> v;
    for(int i = 0; i < 10; ++i) {
        v.push_back(rand() % 101);
    }
    int res = quickselect(v, 0, v.size() - 1, 0);
    quicksort(v, 0, v.size() - 1);
    cout << "The 3rd smallest element is: " << res << endl;
    cout << "The sorted array is: ";
    for (auto i : v) {
        cout << i << " ";
    }


    return 0;
}