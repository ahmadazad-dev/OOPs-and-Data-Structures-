//#include <iostream>
//using namespace std;
//
//const int MAX_BOOKS = 500;                 // not directly used for dynamic nodes but guidance
//const int MAX_USERS = 500;
//const int MAX_AUTHORS_PER_BOOK = 5;
//const int MAX_NAME_TITLE_LEN = 100;        // includes terminating null
//const int MAX_BORROWED_PER_USER = 10;
//const int MAX_HEAP_SIZE = 200;
//const int BORROW_PERIOD_DAYS = 14;         // predefined borrow period
//const int FINE_PER_DAY = 1;                // $1 per overdue day
//
///* ===========================
//   Simple manual "string" helpers
//   (work on null-terminated char arrays)
//   =========================== */
//
//int str_len(const char* s) {
//    int i = 0;
//    if (!s) return 0;
//    while (s[i] != '\0') ++i;
//    return i;
//}
//
//void str_copy(char* dest, const char* src, int max_len) {
//    if (!dest || !src) return;
//    int i = 0;
//    while (i < max_len - 1 && src[i] != '\0') {
//        dest[i] = src[i];
//        ++i;
//    }
//    dest[i] = '\0';
//}
//
//int str_cmp(const char* a, const char* b) {
//    int i = 0;
//    while (a[i] != '\0' && b[i] != '\0') {
//        if (a[i] < b[i]) return -1;
//        if (a[i] > b[i]) return 1;
//        ++i;
//    }
//    if (a[i] == '\0' && b[i] == '\0') return 0;
//    if (a[i] == '\0') return -1;
//    return 1;
//}
//
//void str_trim_inplace(char* s) {
//    // remove leading and trailing spaces (space and tab)
//    if (!s) return;
//    int len = str_len(s);
//    int start = 0;
//    while (start < len && (s[start] == ' ' || s[start] == '\t')) ++start;
//    int end = len - 1;
//    while (end >= start && (s[end] == ' ' || s[end] == '\t')) --end;
//    int j = 0;
//    for (int i = start; i <= end; ++i) {
//        s[j++] = s[i];
//    }
//    s[j] = '\0';
//}
//
///* safe input reading for char arrays using std::cin.getline */
//void input_line(char* buffer, int max_len) {
//    if (!buffer) return;
//    std::cin.getline(buffer, max_len);
//    // handle case when previous extraction left newline: if first char is '\0', read again
//    if (buffer[0] == '\0') {
//        // try reading again (if there was a leftover newline)
//        std::cin.getline(buffer, max_len);
//    }
//}
//
///* parse integer from char digits (no sign) */
//int parse_int_from_chars(const char* s) {
//    int i = 0;
//    int val = 0;
//    while (s[i] != '\0') {
//        char c = s[i];
//        if (c >= '0' && c <= '9') {
//            val = val * 10 + (c - '0');
//        }
//        else {
//            // ignore non-digit
//        }
//        ++i;
//    }
//    return val;
//}
//
///* ===========================
//   Date utilities (yyyy-mm-dd)
//   Simple date: year, month, day as ints
//   No leap-second sophistication; simple proleptic Gregorian calculations
//   =========================== */
//
//struct date_t {
//    int year;
//    int month;
//    int day;
//};
//
//bool parse_date(const char* s, date_t& out_date) {
//    // expects exactly "yyyy-mm-dd" or similar; tolerates extra spaces
//    if (!s) return false;
//    // copy to temp buffer
//    char buf[32];
//    str_copy(buf, s, 32);
//    str_trim_inplace(buf);
//    // find parts
//    int len = str_len(buf);
//    if (len < 8) return false;
//    int i = 0;
//    char year_s[8] = { 0 };
//    char month_s[4] = { 0 };
//    char day_s[4] = { 0 };
//    int yi = 0, mi = 0, di = 0;
//    // read year until '-'
//    while (buf[i] != '\0' && buf[i] != '-') {
//        if (yi < 7) year_s[yi++] = buf[i];
//        ++i;
//    }
//    if (buf[i] == '-') ++i;
//    while (buf[i] != '\0' && buf[i] != '-') {
//        if (mi < 3) month_s[mi++] = buf[i];
//        ++i;
//    }
//    if (buf[i] == '-') ++i;
//    while (buf[i] != '\0') {
//        if (di < 3) day_s[di++] = buf[i];
//        ++i;
//    }
//    year_s[yi] = '\0';
//    month_s[mi] = '\0';
//    day_s[di] = '\0';
//    int y = parse_int_from_chars(year_s);
//    int m = parse_int_from_chars(month_s);
//    int d = parse_int_from_chars(day_s);
//    if (y <= 0 || m <= 0 || d <= 0) return false;
//    if (m > 12) return false;
//    // days per month simple check
//    int mdays = 31;
//    if (m == 4 || m == 6 || m == 9 || m == 11) mdays = 30;
//    else if (m == 2) {
//        // leap year check
//        bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
//        mdays = leap ? 29 : 28;
//    }
//    if (d > mdays) return false;
//    out_date.year = y;
//    out_date.month = m;
//    out_date.day = d;
//    return true;
//}
//
///* convert date to days since epoch 0001-01-01 (approx) for difference calculation.
//   Use the algorithm counting days in year cycles; adequate for differences in modern ranges.
//*/
//long long date_to_days(const date_t& dt) {
//    // Use a simplified days count: count days by years, months, days.
//    // This function is not optimized but suffices for difference in days.
//    int y = dt.year;
//    int m = dt.month;
//    int d = dt.day;
//    // Convert month/day to days in year using month lengths
//    long long days = 0;
//    // days for previous full years
//    long long full_years = y - 1;
//    days += full_years * 365LL;
//    // add leap days
//    days += full_years / 4 - full_years / 100 + full_years / 400;
//    // add days for months in current year
//    int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    bool leap = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
//    for (int i = 1; i < m; ++i) {
//        days += month_days[i];
//        if (i == 2 && leap) days += 1;
//    }
//    days += d;
//    return days;
//}
//
//long long days_between(const date_t& a, const date_t& b) {
//    long long da = date_to_days(a);
//    long long db = date_to_days(b);
//    return db - da; // positive if b after a
//}
//
///* ===========================
//   MinHeap for borrow requests
//   =========================== */
//
//struct borrow_request_t {
//    long long user_id;
//    date_t request_date;
//    int request_seq; // tie-breaker for identical dates
//};
//
//struct min_heap_t {
//    borrow_request_t arr[MAX_HEAP_SIZE];
//    int size;
//};
//
//void min_heap_init(min_heap_t* heap_ptr) {
//    if (!heap_ptr) return;
//    heap_ptr->size = 0;
//}
//
//bool min_heap_is_empty(const min_heap_t* heap_ptr) {
//    return heap_ptr->size <= 0;
//}
//
//int min_heap_size(const min_heap_t* heap_ptr) {
//    return heap_ptr->size;
//}
//
///* compare two requests: earlier request_date has higher priority (less),
//   if equal, lower request_seq has higher priority */
//bool borrow_request_less(const borrow_request_t& a, const borrow_request_t& b) {
//    long long diff = days_between(a.request_date, b.request_date);
//    if (diff < 0) return true;
//    if (diff > 0) return false;
//    // same day -> compare seq
//    return a.request_seq < b.request_seq;
//}
//
//void min_heap_swap(borrow_request_t& a, borrow_request_t& b) {
//    borrow_request_t tmp = a;
//    a = b;
//    b = tmp;
//}
//
//void min_heap_heapify_up(min_heap_t* heap_ptr, int idx) {
//    while (idx > 0) {
//        int parent = (idx - 1) / 2;
//        if (!borrow_request_less(heap_ptr->arr[idx], heap_ptr->arr[parent])) break;
//        min_heap_swap(heap_ptr->arr[idx], heap_ptr->arr[parent]);
//        idx = parent;
//    }
//}
//
//void min_heap_heapify_down(min_heap_t* heap_ptr, int idx) {
//    int n = heap_ptr->size;
//    while (true) {
//        int l = idx * 2 + 1;
//        int r = idx * 2 + 2;
//        int smallest = idx;
//        if (l < n && borrow_request_less(heap_ptr->arr[l], heap_ptr->arr[smallest])) smallest = l;
//        if (r < n && borrow_request_less(heap_ptr->arr[r], heap_ptr->arr[smallest])) smallest = r;
//        if (smallest == idx) break;
//        min_heap_swap(heap_ptr->arr[idx], heap_ptr->arr[smallest]);
//        idx = smallest;
//    }
//}
//
//bool min_heap_push(min_heap_t* heap_ptr, const borrow_request_t& req) {
//    if (heap_ptr->size >= MAX_HEAP_SIZE) return false;
//    heap_ptr->arr[heap_ptr->size] = req;
//    min_heap_heapify_up(heap_ptr, heap_ptr->size);
//    heap_ptr->size += 1;
//    return true;
//}
//
//bool min_heap_pop(min_heap_t* heap_ptr, borrow_request_t& out_req) {
//    if (heap_ptr->size <= 0) return false;
//    out_req = heap_ptr->arr[0];
//    heap_ptr->size -= 1;
//    if (heap_ptr->size > 0) {
//        heap_ptr->arr[0] = heap_ptr->arr[heap_ptr->size];
//        min_heap_heapify_down(heap_ptr, 0);
//    }
//    return true;
//}
//
//bool min_heap_peek(const min_heap_t* heap_ptr, borrow_request_t& out_req) {
//    if (heap_ptr->size <= 0) return false;
//    out_req = heap_ptr->arr[0];
//    return true;
//}
//
///* ===========================
//   Book BST (by ISSN)
//   =========================== */
//
//struct book_node_t {
//    long long issn;
//    char title[MAX_NAME_TITLE_LEN];
//    char authors[MAX_AUTHORS_PER_BOOK][MAX_NAME_TITLE_LEN];
//    int authors_count;
//    int reference_copies;
//    int issuable_copies;
//    min_heap_t demand_heap;
//    int next_request_seq; // to ensure unique sequence per request
//    // BST pointers
//    book_node_t* left;
//    book_node_t* right;
//    book_node_t* parent;
//};
//
//book_node_t* create_book_node(long long issn, const char* title, char authors[][MAX_NAME_TITLE_LEN], int authors_count, int ref_copies, int issue_copies) {
//    book_node_t* n = new book_node_t;
//    n->issn = issn;
//    str_copy(n->title, title, MAX_NAME_TITLE_LEN);
//    n->authors_count = 0;
//    for (int i = 0; i < authors_count && i < MAX_AUTHORS_PER_BOOK; ++i) {
//        str_copy(n->authors[i], authors[i], MAX_NAME_TITLE_LEN);
//        n->authors_count++;
//    }
//    n->reference_copies = ref_copies;
//    n->issuable_copies = issue_copies;
//    min_heap_init(&n->demand_heap);
//    n->next_request_seq = 1;
//    n->left = n->right = n->parent = nullptr;
//    return n;
//}
//
//book_node_t* book_bst_insert(book_node_t* root, book_node_t* new_node) {
//    if (!new_node) return root;
//    if (!root) return new_node;
//    book_node_t* cur = root;
//    book_node_t* parent = nullptr;
//    while (cur) {
//        parent = cur;
//        if (new_node->issn < cur->issn) cur = cur->left;
//        else if (new_node->issn > cur->issn) cur = cur->right;
//        else {
//            // existing ISSN: update fields (except ISSN) and free new_node
//            str_copy(cur->title, new_node->title, MAX_NAME_TITLE_LEN);
//            cur->authors_count = new_node->authors_count;
//            for (int i = 0; i < new_node->authors_count && i < MAX_AUTHORS_PER_BOOK; ++i) {
//                str_copy(cur->authors[i], new_node->authors[i], MAX_NAME_TITLE_LEN);
//            }
//            cur->reference_copies = new_node->reference_copies;
//            cur->issuable_copies = new_node->issuable_copies;
//            delete new_node;
//            return root;
//        }
//    }
//    new_node->parent = parent;
//    if (new_node->issn < parent->issn) parent->left = new_node;
//    else parent->right = new_node;
//    return root;
//}
//
//book_node_t* book_bst_search(book_node_t* root, long long issn) {
//    book_node_t* cur = root;
//    while (cur) {
//        if (issn == cur->issn) return cur;
//        if (issn < cur->issn) cur = cur->left;
//        else cur = cur->right;
//    }
//    return nullptr;
//}
//
//book_node_t* book_bst_find_min(book_node_t* node) {
//    if (!node) return nullptr;
//    while (node->left) node = node->left;
//    return node;
//}
//
//book_node_t* book_bst_transplant(book_node_t* root, book_node_t* u, book_node_t* v) {
//    if (!u->parent) {
//        root = v;
//    }
//    else if (u == u->parent->left) {
//        u->parent->left = v;
//    }
//    else {
//        u->parent->right = v;
//    }
//    if (v) v->parent = u->parent;
//    return root;
//}
//
//book_node_t* book_bst_delete(book_node_t* root, long long issn) {
//    book_node_t* node = book_bst_search(root, issn);
//    if (!node) return root;
//    if (!node->left) {
//        root = book_bst_transplant(root, node, node->right);
//    }
//    else if (!node->right) {
//        root = book_bst_transplant(root, node, node->left);
//    }
//    else {
//        book_node_t* y = book_bst_find_min(node->right);
//        if (y->parent != node) {
//            root = book_bst_transplant(root, y, y->right);
//            y->right = node->right;
//            if (y->right) y->right->parent = y;
//        }
//        root = book_bst_transplant(root, node, y);
//        y->left = node->left;
//        if (y->left) y->left->parent = y;
//    }
//    delete node;
//    return root;
//}
//
//void book_bst_inorder_traverse(book_node_t* root, void (*visit)(book_node_t*)) {
//    if (!root) return;
//    book_bst_inorder_traverse(root->left, visit);
//    visit(root);
//    book_bst_inorder_traverse(root->right, visit);
//}
//
//void free_book_bst(book_node_t* root) {
//    if (!root) return;
//    free_book_bst(root->left);
//    free_book_bst(root->right);
//    delete root;
//}
//
///* ===========================
//   User AVL Tree (by user_id)
//   =========================== */
//
//struct borrowed_entry_t {
//    long long issn;
//    date_t borrow_date;
//};
//
//struct user_node_t {
//    long long user_id;
//    char name[MAX_NAME_TITLE_LEN];
//    borrowed_entry_t borrowed_list[MAX_BORROWED_PER_USER];
//    int borrowed_count;
//    int fine_amount; // integer dollars
//    int height;
//    user_node_t* left;
//    user_node_t* right;
//    user_node_t* parent;
//};
//
//user_node_t* create_user_node(long long user_id, const char* name) {
//    user_node_t* n = new user_node_t;
//    n->user_id = user_id;
//    str_copy(n->name, name, MAX_NAME_TITLE_LEN);
//    n->borrowed_count = 0;
//    n->fine_amount = 0;
//    n->height = 1;
//    n->left = n->right = n->parent = nullptr;
//    return n;
//}
//
//int user_node_height(user_node_t* node) {
//    return node ? node->height : 0;
//}
//
//void user_update_height(user_node_t* node) {
//    if (!node) return;
//    int hl = user_node_height(node->left);
//    int hr = user_node_height(node->right);
//    node->height = (hl > hr ? hl : hr) + 1;
//}
//
//int user_balance_factor(user_node_t* node) {
//    if (!node) return 0;
//    return user_node_height(node->left) - user_node_height(node->right);
//}
//
//user_node_t* user_rotate_right(user_node_t* y) {
//    user_node_t* x = y->left;
//    user_node_t* T2 = x->right;
//    x->right = y;
//    y->left = T2;
//    if (T2) T2->parent = y;
//    x->parent = y->parent;
//    y->parent = x;
//    user_update_height(y);
//    user_update_height(x);
//    return x;
//}
//
//user_node_t* user_rotate_left(user_node_t* x) {
//    user_node_t* y = x->right;
//    user_node_t* T2 = y->left;
//    y->left = x;
//    x->right = T2;
//    if (T2) T2->parent = x;
//    y->parent = x->parent;
//    x->parent = y;
//    user_update_height(x);
//    user_update_height(y);
//    return y;
//}
//
//user_node_t* user_avl_insert(user_node_t* root, user_node_t* new_node) {
//    if (!new_node) return root;
//    if (!root) return new_node;
//    if (new_node->user_id < root->user_id) {
//        root->left = user_avl_insert(root->left, new_node);
//        if (root->left) root->left->parent = root;
//    }
//    else if (new_node->user_id > root->user_id) {
//        root->right = user_avl_insert(root->right, new_node);
//        if (root->right) root->right->parent = root;
//    }
//    else {
//        // update
//        str_copy(root->name, new_node->name, MAX_NAME_TITLE_LEN);
//        delete new_node;
//        return root;
//    }
//    user_update_height(root);
//    int balance = user_balance_factor(root);
//    // Left Left
//    if (balance > 1 && new_node->user_id < root->left->user_id) {
//        return user_rotate_right(root);
//    }
//    // Right Right
//    if (balance < -1 && new_node->user_id > root->right->user_id) {
//        return user_rotate_left(root);
//    }
//    // Left Right
//    if (balance > 1 && new_node->user_id > root->left->user_id) {
//        root->left = user_rotate_left(root->left);
//        if (root->left) root->left->parent = root;
//        return user_rotate_right(root);
//    }
//    // Right Left
//    if (balance < -1 && new_node->user_id < root->right->user_id) {
//        root->right = user_rotate_right(root->right);
//        if (root->right) root->right->parent = root;
//        return user_rotate_left(root);
//    }
//    return root;
//}
//
//user_node_t* user_find_min(user_node_t* node) {
//    if (!node) return nullptr;
//    while (node->left) node = node->left;
//    return node;
//}
//
//user_node_t* user_avl_delete(user_node_t* root, long long user_id) {
//    if (!root) return root;
//    if (user_id < root->user_id) {
//        root->left = user_avl_delete(root->left, user_id);
//        if (root->left) root->left->parent = root;
//    }
//    else if (user_id > root->user_id) {
//        root->right = user_avl_delete(root->right, user_id);
//        if (root->right) root->right->parent = root;
//    }
//    else {
//        // found
//        if (!root->left || !root->right) {
//            user_node_t* temp = root->left ? root->left : root->right;
//            if (!temp) {
//                // no child
//                temp = root;
//                root = nullptr;
//                delete temp;
//            }
//            else {
//                // one child: copy data
//                *root = *temp;
//                delete temp;
//            }
//        }
//        else {
//            user_node_t* temp = user_find_min(root->right);
//            root->user_id = temp->user_id;
//            str_copy(root->name, temp->name, MAX_NAME_TITLE_LEN);
//            root->borrowed_count = temp->borrowed_count;
//            for (int i = 0; i < temp->borrowed_count; ++i) {
//                root->borrowed_list[i] = temp->borrowed_list[i];
//            }
//            root->fine_amount = temp->fine_amount;
//            root->right = user_avl_delete(root->right, temp->user_id);
//            if (root->right) root->right->parent = root;
//        }
//    }
//    if (!root) return root;
//    user_update_height(root);
//    int balance = user_balance_factor(root);
//    if (balance > 1 && user_balance_factor(root->left) >= 0) return user_rotate_right(root);
//    if (balance > 1 && user_balance_factor(root->left) < 0) {
//        root->left = user_rotate_left(root->left);
//        if (root->left) root->left->parent = root;
//        return user_rotate_right(root);
//    }
//    if (balance < -1 && user_balance_factor(root->right) <= 0) return user_rotate_left(root);
//    if (balance < -1 && user_balance_factor(root->right) > 0) {
//        root->right = user_rotate_right(root->right);
//        if (root->right) root->right->parent = root;
//        return user_rotate_left(root);
//    }
//    return root;
//}
//
//user_node_t* user_avl_search(user_node_t* root, long long user_id) {
//    user_node_t* cur = root;
//    while (cur) {
//        if (user_id == cur->user_id) return cur;
//        if (user_id < cur->user_id) cur = cur->left;
//        else cur = cur->right;
//    }
//    return nullptr;
//}
//
//void user_inorder_traverse(user_node_t* root, void (*visit)(user_node_t*)) {
//    if (!root) return;
//    user_inorder_traverse(root->left, visit);
//    visit(root);
//    user_inorder_traverse(root->right, visit);
//}
//
//void free_user_avl(user_node_t* root) {
//    if (!root) return;
//    free_user_avl(root->left);
//    free_user_avl(root->right);
//    delete root;
//}
//
///* ===========================
//   Integration functions
//   =========================== */
//
//   /* utilities for printing */
//void print_book_brief(const book_node_t* b) {
//    if (!b) return;
//    cout << "ISSN: " << b->issn << ", Title: ";
//    cout << b->title << ", Issuable: " << b->issuable_copies << ", Pending: " << min_heap_size(&b->demand_heap) << "\n";
//}
//
//void print_book_full(const book_node_t* b) {
//    if (!b) return;
//    cout << "ISSN: " << b->issn << "\nTitle: " << b->title << "\nAuthors: ";
//    for (int i = 0; i < b->authors_count; ++i) {
//        cout << b->authors[i];
//        if (i + 1 < b->authors_count) cout << "; ";
//    }
//    cout << "\nReference copies: " << b->reference_copies << "\nIssuable copies: " << b->issuable_copies;
//    cout << "\nPending requests: " << min_heap_size(&b->demand_heap) << "\n";
//}
//
//void print_user_full(const user_node_t* u) {
//    if (!u) return;
//    cout << "User ID: " << u->user_id << ", Name: " << u->name << "\nBorrowed count: " << u->borrowed_count << "\n";
//    for (int i = 0; i < u->borrowed_count; ++i) {
//        cout << "  - ISSN: " << u->borrowed_list[i].issn << ", Borrow date: ";
//        cout << u->borrowed_list[i].borrow_date.year << "-";
//        if (u->borrowed_list[i].borrow_date.month < 10) cout << "0";
//        cout << u->borrowed_list[i].borrow_date.month << "-";
//        if (u->borrowed_list[i].borrow_date.day < 10) cout << "0";
//        cout << u->borrowed_list[i].borrow_date.day << "\n";
//    }
//    cout << "Outstanding fine: $" << u->fine_amount << "\n";
//}
//
///* add borrow entry to user (if space) */
//bool user_add_borrowed(user_node_t* user_ptr, long long issn, const date_t& borrow_date) {
//    if (!user_ptr) return false;
//    if (user_ptr->borrowed_count >= MAX_BORROWED_PER_USER) return false;
//    user_ptr->borrowed_list[user_ptr->borrowed_count].issn = issn;
//    user_ptr->borrowed_list[user_ptr->borrowed_count].borrow_date = borrow_date;
//    user_ptr->borrowed_count += 1;
//    return true;
//}
//
///* remove book from user's borrowed list (by issn), return true if removed and set borrow_date_out */
//bool user_remove_borrowed(user_node_t* user_ptr, long long issn, date_t& borrow_date_out) {
//    if (!user_ptr) return false;
//    int idx = -1;
//    for (int i = 0; i < user_ptr->borrowed_count; ++i) {
//        if (user_ptr->borrowed_list[i].issn == issn) {
//            idx = i;
//            break;
//        }
//    }
//    if (idx == -1) return false;
//    borrow_date_out = user_ptr->borrowed_list[idx].borrow_date;
//    // shift remaining entries
//    for (int i = idx; i + 1 < user_ptr->borrowed_count; ++i) {
//        user_ptr->borrowed_list[i] = user_ptr->borrowed_list[i + 1];
//    }
//    user_ptr->borrowed_count -= 1;
//    return true;
//}
//
///* serve next request for a book if issuable copies exist */
//bool serve_next_request_if_any(book_node_t* book_ptr, user_node_t* users_root) {
//    if (!book_ptr) return false;
//    if (book_ptr->issuable_copies <= 0) return false;
//    if (min_heap_is_empty(&book_ptr->demand_heap)) return false;
//    borrow_request_t next_req;
//    if (!min_heap_pop(&book_ptr->demand_heap, next_req)) return false;
//    // find user
//    user_node_t* user_ptr = user_avl_search(users_root, next_req.user_id);
//    if (!user_ptr) {
//        // user not found, skip and attempt next
//        return serve_next_request_if_any(book_ptr, users_root);
//    }
//    // issue book
//    date_t borrow_date = next_req.request_date;
//    bool ok = user_add_borrowed(user_ptr, book_ptr->issn, borrow_date);
//    if (ok) {
//        book_ptr->issuable_copies -= 1;
//        // printed message will be handled by caller
//        return true;
//    }
//    else {
//        // cannot add to user's borrowed list (limit), skip and attempt next
//        return serve_next_request_if_any(book_ptr, users_root);
//    }
//}
//
///* borrow_book: adds request and if possible issues immediately */
//bool borrow_book_process(book_node_t* book_ptr, user_node_t* users_root, long long user_id, const date_t& request_date, char output_message[], int out_msg_len) {
//    if (!book_ptr || !users_root) {
//        if (out_msg_len > 0) {
//            str_copy(output_message, "Book or users root invalid.", out_msg_len);
//        }
//        return false;
//    }
//    // ensure user exists
//    user_node_t* user_ptr = user_avl_search(users_root, user_id);
//    if (!user_ptr) {
//        if (out_msg_len > 0) str_copy(output_message, "User not registered.", out_msg_len);
//        return false;
//    }
//    // prepare request
//    borrow_request_t req;
//    req.user_id = user_id;
//    req.request_date = request_date;
//    req.request_seq = book_ptr->next_request_seq++;
//    // push into heap
//    if (!min_heap_push(&book_ptr->demand_heap, req)) {
//        if (out_msg_len > 0) str_copy(output_message, "Request queue full.", out_msg_len);
//        return false;
//    }
//    // if issuable copies available, we should issue to earliest in queue
//    if (book_ptr->issuable_copies > 0) {
//        // peek earliest; if earliest corresponds to this or others, pop and issue
//        borrow_request_t earliest;
//        min_heap_peek(&book_ptr->demand_heap, earliest);
//        // pop earliest and issue
//        borrow_request_t popped;
//        min_heap_pop(&book_ptr->demand_heap, popped);
//        // find user & add borrowed
//        user_node_t* top_user = user_avl_search(users_root, popped.user_id);
//        if (!top_user) {
//            // skip and try next
//            return serve_next_request_if_any(book_ptr, users_root);
//        }
//        else {
//            bool added = user_add_borrowed(top_user, book_ptr->issn, popped.request_date);
//            if (added) {
//                book_ptr->issuable_copies -= 1;
//                if (out_msg_len > 0) {
//                    // form message
//                    char tmp[256];
//                    str_copy(tmp, "Book issued to user.", 256);
//                    str_copy(output_message, tmp, out_msg_len);
//                }
//                return true;
//            }
//            else {
//                // user cannot borrow (limit) -> try next in queue
//                return serve_next_request_if_any(book_ptr, users_root);
//            }
//        }
//    }
//    else {
//        if (out_msg_len > 0) str_copy(output_message, "Request queued; no copies available.", out_msg_len);
//        return true;
//    }
//}
//
///* return_book_process: user returns a book; update copies, fines, and serve next request */
//bool return_book_process(book_node_t* book_ptr, user_node_t* users_root, long long user_id, const date_t& return_date, char output_message[], int out_msg_len) {
//    if (!book_ptr || !users_root) {
//        if (out_msg_len > 0) str_copy(output_message, "Invalid parameters.", out_msg_len);
//        return false;
//    }
//    user_node_t* user_ptr = user_avl_search(users_root, user_id);
//    if (!user_ptr) {
//        if (out_msg_len > 0) str_copy(output_message, "User not found.", out_msg_len);
//        return false;
//    }
//    date_t borrow_date;
//    bool removed = user_remove_borrowed(user_ptr, book_ptr->issn, borrow_date);
//    if (!removed) {
//        if (out_msg_len > 0) str_copy(output_message, "User did not have this book borrowed.", out_msg_len);
//        return false;
//    }
//    // increment issuable copies
//    book_ptr->issuable_copies += 1;
//    // compute due date
//    long long days_diff = days_between(borrow_date, return_date);
//    long long overdue = days_diff - BORROW_PERIOD_DAYS;
//    if (overdue > 0) {
//        int fine_inc = (int)(overdue * FINE_PER_DAY);
//        user_ptr->fine_amount += fine_inc;
//        if (out_msg_len > 0) {
//            char tmp[256];
//            // form message
//            // We'll build "Book returned. Fine added: $X"
//            int idx = 0;
//            const char* pre = "Book returned. Fine added: $";
//            while (pre[idx] != '\0' && idx < out_msg_len - 1) { output_message[idx] = pre[idx]; ++idx; }
//            // append number
//            int write_pos = idx;
//            // convert fine_inc to chars
//            char numbuf[32];
//            int ni = 0;
//            if (fine_inc == 0) { numbuf[ni++] = '0'; }
//            else {
//                int t = fine_inc;
//                char rev[32]; int ri = 0;
//                while (t > 0) { rev[ri++] = (char)('0' + (t % 10)); t /= 10; }
//                for (int j = ri - 1; j >= 0; --j) numbuf[ni++] = rev[j];
//            }
//            numbuf[ni] = '\0';
//            int k = 0;
//            while (numbuf[k] != '\0' && write_pos < out_msg_len - 1) {
//                output_message[write_pos++] = numbuf[k++];
//            }
//            output_message[write_pos] = '\0';
//        }
//    }
//    else {
//        if (out_msg_len > 0) str_copy(output_message, "Book returned. No fine.", out_msg_len);
//    }
//    // after incrementing issuable copies, serve next request if any
//    serve_next_request_if_any(book_ptr, users_root);
//    return true;
//}
//
///* update book fields (title, authors, copies) */
//bool update_book_field(book_node_t* book_ptr, const char* field_name, const char* new_value, int new_int_value) {
//    if (!book_ptr || !field_name) return false;
//    if (str_cmp(field_name, "Title") == 0 || str_cmp(field_name, "title") == 0) {
//        str_copy(book_ptr->title, new_value, MAX_NAME_TITLE_LEN);
//        return true;
//    }
//    else if (str_cmp(field_name, "Authors") == 0 || str_cmp(field_name, "authors") == 0) {
//        // parse comma-separated authors into authors array
//        char tmp[512];
//        str_copy(tmp, new_value, 512);
//        // split by comma
//        int cur = 0;
//        int count = 0;
//        int i = 0;
//        while (true) {
//            char token[MAX_NAME_TITLE_LEN];
//            int ti = 0;
//            // skip leading spaces
//            while (tmp[cur] == ' ' || tmp[cur] == '\t') ++cur;
//            while (tmp[cur] != '\0' && tmp[cur] != ',' && ti < MAX_NAME_TITLE_LEN - 1) {
//                token[ti++] = tmp[cur++];
//            }
//            token[ti] = '\0';
//            str_trim_inplace(token);
//            if (ti > 0 && count < MAX_AUTHORS_PER_BOOK) {
//                str_copy(book_ptr->authors[count++], token, MAX_NAME_TITLE_LEN);
//            }
//            if (tmp[cur] == '\0') break;
//            if (tmp[cur] == ',') ++cur;
//        }
//        book_ptr->authors_count = count;
//        return true;
//    }
//    else if (str_cmp(field_name, "Reference Copies") == 0 || str_cmp(field_name, "reference_copies") == 0) {
//        book_ptr->reference_copies = new_int_value;
//        return true;
//    }
//    else if (str_cmp(field_name, "Issuable Copies") == 0 || str_cmp(field_name, "issuable_copies") == 0) {
//        book_ptr->issuable_copies = new_int_value;
//        return true;
//    }
//    return false;
//}
//
///* find most demanded book */
//void find_most_demanded_book(book_node_t* root, book_node_t** out_best, int* out_max_pending) {
//    if (!root) return;
//    find_most_demanded_book(root->left, out_best, out_max_pending);
//    int pend = min_heap_size(&root->demand_heap);
//    if (pend > *out_max_pending) {
//        *out_max_pending = pend;
//        *out_best = root;
//    }
//    find_most_demanded_book(root->right, out_best, out_max_pending);
//}
//
///* calculate fines for all users by traversing borrowed books to see if overdue as of "today" param
//   Note: the spec asked to compute fines for overdue books not yet returned; however we need a reference date.
//   We'll supply a date and compute fines based on borrow dates + BORROW_PERIOD_DAYS.
//*/
//void calculate_fines_all_users(user_node_t* root, const date_t& today) {
//    if (!root) return;
//    calculate_fines_all_users(root->left, today);
//    // compute for this user
//    for (int i = 0; i < root->borrowed_count; ++i) {
//        date_t borrow_d = root->borrowed_list[i].borrow_date;
//        long long days_diff = days_between(borrow_d, today);
//        long long overdue = days_diff - BORROW_PERIOD_DAYS;
//        if (overdue > 0) {
//            root->fine_amount += (int)(overdue * FINE_PER_DAY);
//        }
//    }
//    calculate_fines_all_users(root->right, today);
//}
//
///* ===========================
//   Console / Menu helpers
//   =========================== */
//
//   /* read integer from console robustly */
//long long input_long_long_prompt(const char* prompt) {
//    cout << prompt;
//    long long val = 0;
//    while (!(cin >> val)) {
//        cout << "Invalid input. Try again: ";
//        cin.clear();
//        cin.ignore(10000, '\n');
//    }
//    cin.ignore(10000, '\n');
//    return val;
//}
//
//int input_int_prompt(const char* prompt) {
//    cout << prompt;
//    int val = 0;
//    while (!(cin >> val)) {
//        cout << "Invalid input. Try again: ";
//        cin.clear();
//        cin.ignore(10000, '\n');
//    }
//    cin.ignore(10000, '\n');
//    return val;
//}
//
///* read text line into buffer */
//void input_text_prompt(const char* prompt, char* buffer, int buffer_len) {
//    cout << prompt;
//    input_line(buffer, buffer_len);
//}
//
///* small helper to read date */
//bool input_date_prompt(const char* prompt, date_t& out_date) {
//    char buf[32];
//    cout << prompt;
//    input_line(buf, 32);
//    bool ok = parse_date(buf, out_date);
//    if (!ok) cout << "Invalid date format. Use yyyy-mm-dd.\n";
//    return ok;
//}
//
///* ===========================
//   Main program menu loop
//   =========================== */
//
//void print_menu() {
//    cout << "\n--- Library Management System ---\n";
//    cout << "1. Add Book\n";
//    cout << "2. Register User\n";
//    cout << "3. Borrow Book (request)\n";
//    cout << "4. Return Book\n";
//    cout << "5. Update Book\n";
//    cout << "6. Delete Book\n";
//    cout << "7. Find Most Demanded Book\n";
//    cout << "8. Display User Record\n";
//    cout << "9. Calculate Fines for All Users (given date)\n";
//    cout << "10. List All Books (inorder)\n";
//    cout << "11. List All Users (inorder)\n";
//    cout << "0. Exit\n";
//}
//
///* helper to parse authors comma-separated into array */
//int parse_authors_input(char authors_arr[][MAX_NAME_TITLE_LEN]) {
//    char line[512];
//    input_line(line, 512);
//    str_trim_inplace(line);
//    int count = 0;
//    int pos = 0;
//    while (line[pos] != '\0' && count < MAX_AUTHORS_PER_BOOK) {
//        // extract token until comma
//        char token[MAX_NAME_TITLE_LEN];
//        int ti = 0;
//        while (line[pos] != '\0' && line[pos] != ',') {
//            if (ti < MAX_NAME_TITLE_LEN - 1) token[ti++] = line[pos];
//            ++pos;
//        }
//        token[ti] = '\0';
//        str_trim_inplace(token);
//        if (str_len(token) > 0) {
//            str_copy(authors_arr[count], token, MAX_NAME_TITLE_LEN);
//            count++;
//        }
//        if (line[pos] == ',') ++pos;
//    }
//    return count;
//}
//
///* main loop */
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    book_node_t* books_root = nullptr;
//    user_node_t* users_root = nullptr;
//
//    cout << "Library Management System (only <iostream>, fixed arrays)\n";
//
//    bool running = true;
//    while (running) {
//        print_menu();
//        int choice = input_int_prompt("Choose option: ");
//        switch (choice) {
//        case 1: { // Add Book
//            long long issn = input_long_long_prompt("Enter ISSN (numeric): ");
//            cout << "Enter Title: ";
//            char title[MAX_NAME_TITLE_LEN];
//            input_line(title, MAX_NAME_TITLE_LEN);
//            cout << "Enter Authors (comma separated, up to " << MAX_AUTHORS_PER_BOOK << "): ";
//            char authors_arr[MAX_AUTHORS_PER_BOOK][MAX_NAME_TITLE_LEN];
//            int authors_count = parse_authors_input(authors_arr);
//            int ref_copies = input_int_prompt("Enter Reference Copies: ");
//            int issue_copies = input_int_prompt("Enter Issuable Copies: ");
//            book_node_t* new_book = create_book_node(issn, title, authors_arr, authors_count, ref_copies, issue_copies);
//            books_root = book_bst_insert(books_root, new_book);
//            cout << "Book added: ISSN: " << issn << ", Title: " << title << "\n";
//            break;
//        }
//        case 2: { // Register User
//            long long user_id = input_long_long_prompt("Enter User ID (numeric): ");
//            cout << "Enter Name: ";
//            char name[MAX_NAME_TITLE_LEN];
//            input_line(name, MAX_NAME_TITLE_LEN);
//            user_node_t* new_user = create_user_node(user_id, name);
//            users_root = user_avl_insert(users_root, new_user);
//            cout << "User registered: User ID: " << user_id << ", Name: " << name << "\n";
//            break;
//        }
//        case 3: { // Borrow Book (request)
//            long long user_id = input_long_long_prompt("Enter User ID: ");
//            long long issn = input_long_long_prompt("Enter ISSN: ");
//            book_node_t* book_ptr = book_bst_search(books_root, issn);
//            if (!book_ptr) {
//                cout << "Book not found.\n";
//                break;
//            }
//            cout << "Enter Request Date (yyyy-mm-dd): ";
//            date_t req_date;
//            if (!input_date_prompt("", req_date)) {
//                break;
//            }
//            char out_msg[256];
//            bool ok = borrow_book_process(book_ptr, users_root, user_id, req_date, out_msg, 256);
//            if (ok) {
//                // if book was issued immediately, inform
//                cout << out_msg << "\n";
//                if (str_len(out_msg) == 0) cout << "Request processed.\n";
//                // Also display book title
//                cout << "Book: ISSN: " << book_ptr->issn << ", Title: " << book_ptr->title << "\n";
//            }
//            else {
//                cout << "Failed: " << out_msg << "\n";
//            }
//            break;
//        }
//        case 4: { // Return Book
//            long long user_id = input_long_long_prompt("Enter User ID: ");
//            long long issn = input_long_long_prompt("Enter ISSN: ");
//            book_node_t* book_ptr = book_bst_search(books_root, issn);
//            if (!book_ptr) {
//                cout << "Book not found.\n";
//                break;
//            }
//            cout << "Enter Return Date (yyyy-mm-dd): ";
//            date_t return_date;
//            if (!input_date_prompt("", return_date)) break;
//            char out_msg[256];
//            bool ok = return_book_process(book_ptr, users_root, user_id, return_date, out_msg, 256);
//            if (ok) cout << out_msg << "\n";
//            else cout << "Return failed: " << out_msg << "\n";
//            break;
//        }
//        case 5: { // Update Book
//            long long issn = input_long_long_prompt("Enter ISSN to update: ");
//            book_node_t* book_ptr = book_bst_search(books_root, issn);
//            if (!book_ptr) {
//                cout << "Book not found.\n";
//                break;
//            }
//            cout << "Fields: Title / Authors / Reference Copies / Issuable Copies\n";
//            cout << "Enter Field to Update (exact): ";
//            char field_name[64];
//            input_line(field_name, 64);
//            if (str_cmp(field_name, "Title") == 0 || str_cmp(field_name, "title") == 0) {
//                cout << "Enter new title: ";
//                char newval[MAX_NAME_TITLE_LEN];
//                input_line(newval, MAX_NAME_TITLE_LEN);
//                update_book_field(book_ptr, "Title", newval, 0);
//                cout << "Book updated: ISSN: " << issn << ", New Title: " << book_ptr->title << "\n";
//            }
//            else if (str_cmp(field_name, "Authors") == 0 || str_cmp(field_name, "authors") == 0) {
//                cout << "Enter new authors (comma separated): ";
//                char newauthors[512];
//                input_line(newauthors, 512);
//                update_book_field(book_ptr, "Authors", newauthors, 0);
//                cout << "Book authors updated.\n";
//            }
//            else if (str_cmp(field_name, "Reference Copies") == 0 || str_cmp(field_name, "reference copies") == 0) {
//                int val = input_int_prompt("Enter new Reference Copies value: ");
//                update_book_field(book_ptr, "Reference Copies", "", val);
//                cout << "Book updated: Reference Copies: " << book_ptr->reference_copies << "\n";
//            }
//            else if (str_cmp(field_name, "Issuable Copies") == 0 || str_cmp(field_name, "issuable copies") == 0) {
//                int val = input_int_prompt("Enter new Issuable Copies value: ");
//                update_book_field(book_ptr, "Issuable Copies", "", val);
//                cout << "Book updated: Issuable Copies: " << book_ptr->issuable_copies << "\n";
//            }
//            else {
//                cout << "Unknown field.\n";
//            }
//            break;
//        }
//        case 6: { // Delete Book
//            long long issn = input_long_long_prompt("Enter ISSN to delete: ");
//            book_node_t* bptr = book_bst_search(books_root, issn);
//            if (!bptr) {
//                cout << "Book not found.\n";
//                break;
//            }
//            char titlebuf[MAX_NAME_TITLE_LEN];
//            str_copy(titlebuf, bptr->title, MAX_NAME_TITLE_LEN);
//            books_root = book_bst_delete(books_root, issn);
//            struct remover_ctx_t { long long issn; };
//            void (*remove_fn)(user_node_t*);
//            // define actual function:
//            struct remover_struct {
//                long long issn_to_remove;
//            } remover_data;
//            remover_data.issn_to_remove = issn;
//            extern long long target_issn_for_removal;
//            target_issn_for_removal = issn;
//            // helper will remove borrowed entries for that issn
//            extern void remove_borrowed_from_user_inorder(user_node_t*);
//            user_inorder_traverse(users_root, remove_borrowed_from_user_inorder);
//            cout << "Book deleted: ISSN: " << issn << ", Title: " << titlebuf << "\n";
//            break;
//        }
//        case 7: { // Find Most Demanded Book
//            book_node_t* best = nullptr;
//            int max_pending = -1;
//            find_most_demanded_book(books_root, &best, &max_pending);
//            if (best) {
//                cout << "Most Demanded Book: " << best->title << ", ISSN: " << best->issn << ", Pending Requests: " << max_pending << "\n";
//            }
//            else {
//                cout << "No books found.\n";
//            }
//            break;
//        }
//        case 8: { // Display User Record
//            long long uid = input_long_long_prompt("Enter User ID: ");
//            user_node_t* uptr = user_avl_search(users_root, uid);
//            if (!uptr) {
//                cout << "User not found.\n";
//            }
//            else {
//                print_user_full(uptr);
//            }
//            break;
//        }
//        case 9: { // Calculate Fines for All Users
//            cout << "Enter date for fine calculation (yyyy-mm-dd): ";
//            date_t today;
//            if (!input_date_prompt("", today)) break;
//            calculate_fines_all_users(users_root, today);
//            // print users with fines
//            cout << "Users with fines:\n";
//            // traverse and print if fine>0
//            struct print_fines_ctx { int dummy; };
//            // we'll use a simple traversal function that prints fines
//            extern void print_fines_if_any(user_node_t*);
//            print_fines_if_any(users_root);
//            break;
//        }
//        case 10: { // List All Books
//            if (!books_root) {
//                cout << "No books.\n";
//            }
//            else {
//                cout << "Books list (inorder):\n";
//                book_bst_inorder_traverse(books_root, [](book_node_t* b) { print_book_brief(b); });
//            }
//            break;
//        }
//        case 11: { // List All Users
//            if (!users_root) {
//                cout << "No users.\n";
//            }
//            else {
//                cout << "Users list (inorder):\n";
//                user_inorder_traverse(users_root, [](user_node_t* u) { cout << "User ID: " << u->user_id << ", Name: " << u->name << ", Fine: $" << u->fine_amount << "\n"; });
//            }
//            break;
//        }
//        case 0:
//            running = false;
//            break;
//        default:
//            cout << "Unknown option.\n";
//        }
//    }
//
//    free_book_bst(books_root);
//    free_user_avl(users_root);
//
//    cout << "Exiting.\n";
//    return 0;
//}
//
//long long target_issn_for_removal = -1;
//
//void remove_borrowed_from_user_inorder(user_node_t* user_ptr) {
//    if (!user_ptr) return;
//    bool changed = true;
//    while (changed) {
//        changed = false;
//        for (int i = 0; i < user_ptr->borrowed_count; ++i) {
//            if (user_ptr->borrowed_list[i].issn == target_issn_for_removal) {
//                // remove at i
//                for (int j = i; j + 1 < user_ptr->borrowed_count; ++j) {
//                    user_ptr->borrowed_list[j] = user_ptr->borrowed_list[j + 1];
//                }
//                user_ptr->borrowed_count -= 1;
//                changed = true;
//                break;
//            }
//        }
//    }
//}
//
//void print_fines_if_any(user_node_t* user_ptr) {
//    if (!user_ptr) return;
//    print_fines_if_any(user_ptr->left);
//    if (user_ptr->fine_amount > 0) {
//        cout << "User ID: " << user_ptr->user_id << ", Fine: $" << user_ptr->fine_amount << "\n";
//    }
//    print_fines_if_any(user_ptr->right);
//}
