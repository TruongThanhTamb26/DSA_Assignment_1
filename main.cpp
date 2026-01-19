#include "Playlist.h"
#include "BotkifyLinkedList.h"

int main() {
    // Student can use this main function to do some basic testing
    Song song(1, "doi", "52Hz", "cho", 460, 90, "no");
    cout << song.getID();
    cout << song.getDuration();
    cout << song.getScore() << endl;

    BotkifyLinkedList<int> list;

    cout << "=== Test add(e) ===\n";
    list.add(10);
    list.add(20);
    list.add(30);
    cout << "List: " << list.toString() << endl;   // 10,20,30

    cout << "\n=== Test add(index, e) ===\n";
    list.add(0, 5);    // add head
    list.add(2, 15);   // add middle
    list.add(list.size(), 40); // add tail
    cout << "List: " << list.toString() << endl;   // 5,10,15,20,30,40

    cout << "\n=== Test get(index) ===\n";
    cout << "get(0): " << list.get(0) << endl;
    cout << "get(3): " << list.get(3) << endl;

    cout << "\n=== Test modify via get(index) ===\n";
    list.get(1) = 100;     // sửa trực tiếp node
    cout << "List: " << list.toString() << endl;   // 5,100,15,20,30,40

    cout << "\n=== Test removeAt(index) ===\n";
    int removed = list.removeAt(2);  // remove 15
    cout << "Removed: " << removed << endl;
    cout << "List: " << list.toString() << endl;

    cout << "\n=== Test removeItem(value) ===\n";
    bool ok = list.removeItem(20);
    cout << "removeItem(20): " << (ok ? "true" : "false") << endl;
    cout << "List: " << list.toString() << endl;

    cout << "\n=== Test removeItem(value not exist) ===\n";
    ok = list.removeItem(999);
    cout << "removeItem(999): " << (ok ? "true" : "false") << endl;
    cout << "List: " << list.toString() << endl;

    cout << "\n=== Test size & empty ===\n";
    cout << "Size: " << list.size() << endl;
    cout << "Empty: " << (list.empty() ? "true" : "false") << endl;

    cout << "\n=== Test clear() ===\n";
    list.clear();
    cout << "List after clear: \"" << list.toString() << "\"\n";
    cout << "Size: " << list.size() << endl;
    cout << "Empty: " << (list.empty() ? "true" : "false") << endl;

    cout << "\n=== Test exception ===\n";
    try {
        list.get(0);   // invalid
    } catch (const out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n=== DONE ===\n";
    return 0;
}