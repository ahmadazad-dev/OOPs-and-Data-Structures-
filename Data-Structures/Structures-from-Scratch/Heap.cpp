//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//class Heap {
//private:
//    T* store_block;
//    int max_limit;
//    int curr_count;
//
//    void shift_up(int pos) {
//        if (pos == 0) return;
//
//        int p_index = (pos - 1) / 2;
//
//        if (store_block[pos].energy_val > store_block[p_index].energy_val) {
//            T temp_item = store_block[pos];
//            store_block[pos] = store_block[p_index];
//            store_block[p_index] = temp_item;
//            shift_up(p_index);
//        }
//    }
//
//    void shift_down(int pos) {
//        int l_child = 2 * pos + 1;
//        int r_child = 2 * pos + 2;
//        int big_pos = pos;
//
//        if (l_child < curr_count && store_block[l_child].energy_val > store_block[big_pos].energy_val) {
//            big_pos = l_child;
//        }
//
//        if (r_child < curr_count && store_block[r_child].energy_val > store_block[big_pos].energy_val) {
//            big_pos = r_child;
//        }
//
//        if (big_pos != pos) {
//            T temp_item = store_block[pos];
//            store_block[pos] = store_block[big_pos];
//            store_block[big_pos] = temp_item;
//            shift_down(big_pos);
//        }
//    }
//
//    void expand_space() {
//        max_limit *= 2;
//        T* temp_block = new T[max_limit];
//        for (int i = 0; i < curr_count; i++) {
//            temp_block[i] = store_block[i];
//        }
//        delete[] store_block;
//        store_block = temp_block;
//    }
//
//public:
//    Heap() {
//        max_limit = 10;
//        curr_count = 0;
//        store_block = new T[max_limit];
//    }
//
//    ~Heap() {
//        delete[] store_block;
//    }
//
//    void insert(T new_item) {
//        if (curr_count == max_limit) {
//            expand_space();
//        }
//        store_block[curr_count] = new_item;
//        shift_up(curr_count);
//        curr_count++;
//    }
//
//    T removeTop() {
//        if (curr_count == 0) {
//            cout << "Heap is empty!" << endl;
//            T empty;
//            return empty;
//        }
//
//        T front_item = store_block[0];
//        store_block[0] = store_block[curr_count - 1];
//        curr_count--;
//        shift_down(0);
//        return front_item;
//    }
//
//    void display(int pos, int lvl) {
//        if (pos >= curr_count) return;
//
//        display(2 * pos + 2, lvl + 1);
//
//        for (int i = 0; i < lvl; i++) {
//            cout << "    ";
//        }
//        cout << store_block[pos].w_name << " (" << store_block[pos].energy_val << ")" << endl;
//
//        display(2 * pos + 1, lvl + 1);
//    }
//
//    void displayHeap() {
//        if (curr_count == 0) {
//            cout << "Heap is empty!" << endl;
//            return;
//        }
//        display(0, 0);
//    }
//
//    void clear() {
//        curr_count = 0;
//        cout << "Heap cleared!" << endl;
//    }
//
//    int getCount() {
//        return curr_count;
//    }
//
//    void increaseReiatsu(int wid, int inc_val) {
//        int pos = -1;
//        for (int i = 0; i < curr_count; i++) {
//            if (store_block[i].wid == wid) {
//                pos = i;
//                break;
//            }
//        }
//
//        if (pos == -1) {
//            cout << "Warrior with ID " << wid << " not found!" << endl;
//            return;
//        }
//
//        store_block[pos].energy_val += inc_val;
//        shift_up(pos);
//        cout << "Reiatsu increased for " << store_block[pos].w_name << "!" << endl;
//    }
//
//    void heapSort(T* sorted_out) {
//        Heap<T> temp_heap;
//        for (int i = 0; i < curr_count; i++) {
//            temp_heap.insert(store_block[i]);
//        }
//
//        for (int i = 0; i < curr_count; i++) {
//            sorted_out[i] = temp_heap.removeTop();
//        }
//    }
//};
//
//struct SpiritFighter {
//    int wid;
//    string w_name;
//    int energy_val;
//
//    SpiritFighter() {
//        wid = 0;
//        w_name = "";
//        energy_val = 0;
//    }
//
//    SpiritFighter(int x, string nm, int ev) {
//        wid = x;
//        w_name = nm;
//        energy_val = ev;
//    }
//};
//
//int main() {
//    Heap<SpiritFighter> fighter_heap;
//    int menu_pick;
//    int new_wid = 1;
//
//    while (true) {
//        cout << "\n=== Soul Heap Menu ===" << endl;
//        cout << "1. Add new warrior" << endl;
//        cout << "2. Remove top warrior" << endl;
//        cout << "3. Display heap hierarchy" << endl;
//        cout << "4. Clear the heap" << endl;
//        cout << "5. Get count of warriors" << endl;
//        cout << "6. Increase reiatsu of a warrior" << endl;
//        cout << "7. Sort warriors using heapsort" << endl;
//        cout << "8. Exit" << endl;
//        cout << "Enter choice: ";
//        cin >> menu_pick;
//
//        if (menu_pick == 1) {
//            string temp_nm;
//            int temp_ev;
//            cout << "Enter warrior name: ";
//            cin >> temp_nm;
//            cout << "Enter reiatsu: ";
//            cin >> temp_ev;
//
//            SpiritFighter fighter(new_wid++, temp_nm, temp_ev);
//            fighter_heap.insert(fighter);
//            cout << "Warrior added!" << endl;
//        }
//        else if (menu_pick == 2) {
//            SpiritFighter got = fighter_heap.removeTop();
//            if (got.wid != 0) {
//                cout << "Removed: " << got.w_name << " (Reiatsu: " << got.energy_val << ")" << endl;
//            }
//        }
//        else if (menu_pick == 3) {
//            cout << "\nHeap Hierarchy:" << endl;
//            fighter_heap.displayHeap();
//        }
//        else if (menu_pick == 4) {
//            fighter_heap.clear();
//        }
//        else if (menu_pick == 5) {
//            cout << "Total warriors: " << fighter_heap.getCount() << endl;
//        }
//        else if (menu_pick == 6) {
//            int id_in, inc_val;
//            cout << "Enter warrior ID: ";
//            cin >> id_in;
//            cout << "Enter reiatsu increase amount: ";
//            cin >> inc_val;
//            fighter_heap.increaseReiatsu(id_in, inc_val);
//        }
//        else if (menu_pick == 7) {
//            int cnt = fighter_heap.getCount();
//            if (cnt == 0) {
//                cout << "Heap is empty!" << endl;
//            }
//            else {
//                SpiritFighter* sorted = new SpiritFighter[cnt];
//                fighter_heap.heapSort(sorted);
//
//                cout << "\nSorted Warriors (Descending Reiatsu):" << endl;
//                for (int i = 0; i < cnt; i++) {
//                    cout << sorted[i].w_name << " (ID: " << sorted[i].wid
//                        << ", Reiatsu: " << sorted[i].energy_val << ")" << endl;
//                }
//
//                delete[] sorted;
//            }
//        }
//        else if (menu_pick == 8) {
//            break;
//        }
//        else {
//            cout << "Invalid choice!" << endl;
//        }
//    }
//
//    return 0;
//}
