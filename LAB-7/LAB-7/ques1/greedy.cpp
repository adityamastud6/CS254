#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};

bool cmp(const Item &a, const Item &b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main(){
    int n, WeightLimit;
    cin >> n >> WeightLimit;
    vector<Item> items;
    for (int i = 0; i < n; i++){
        int value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }
    sort(items.begin(), items.end(), cmp);

    int totalValue = 0;
    for (const auto &item : items){
        if (WeightLimit >= item.weight){
            WeightLimit -= item.weight;
            totalValue += item.value;
        }
        else{
            break;
        }
    }

    cout << "Total value: " << totalValue << endl;
    return 0;
}

// T.C. - O(n.log(n))