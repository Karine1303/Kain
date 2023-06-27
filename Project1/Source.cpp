#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 - 2;
    size_t number_count, bin_count;
    int max_count = -1;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector<double> numbers(number_count);
    for (int i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }
    cerr << "Enter bin count: ";
    cin >> bin_count;
    vector<size_t> bins(bin_count);
    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
    cerr << "max:" << max << endl;
    cerr << "min:" << min << endl;
    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
    for (double x : bins) {
        if (x > max_count) {
            max_count = x;
        }
    }
    cerr << endl;

    for (int i = 0; i < bin_count; i++)
    {
        if (bins[i] < 100) {
            cout << ' ';
        }
        if (bins[i] < 10) {
            cout << ' ';
        }

        cout << bins[i] << "|";

        size_t height;
        if (max_count > MAX_ASTERISK) {
            if (bins[i] > MAX_ASTERISK) {
                height = MAX_ASTERISK * 1.0;
            }
            else {
                height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
            }
        }
        else {
            height = bins[i];
        }

        for (int j = 0; j < height; j++) {
            if (i == 0) {
                if ((bins[i] > bins[i + 1]) && (j == bins[i + 1] - 1)) {
                    cout << 'v';
                }
                else if ((bins[i] == bins[i + 1]) && (j == bins[i + 1] - 1)) {
                    cout << 'N';
                }
                else {
                    cout << "*";
                }
            }
            else if (i != 0 && i < bin_count - 1) {
                if ((bins[i] > bins[i + 1]) && (j == bins[i + 1] - 1)) {
                    cout << 'v';
                }
                else if ((bins[i] == bins[i + 1]) && (j == bins[i + 1] - 1)) {
                    cout << 'N';
                }
                else if ((bins[i] > bins[i - 1]) && (j == bins[i - 1] - 1)) {
                    cout << '^';
                }
                else if ((bins[i] == bins[i - 1]) && (j == bins[i - 1] - 1)) {
                    cout << 'N';
                }
                else {
                    cout << "*";
                }
            }
            else if (i == bin_count - 1) {
                if ((bins[i] > bins[i - 1]) && (j == bins[i - 1] - 1)) {
                    cout << '^';
                }
                else if ((bins[i] == bins[i - 1]) && (j == bins[i - 1] - 1)) {
                    cout << 'N';
                }
                else {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }
    cerr << endl;
    cerr << "max_count " << max_count << endl;

}