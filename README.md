# Dynamic Array in C

This project is a simple implementation of a **dynamic array** (also called a **resizable array**) from scratch using the C programming language.  
It mimics the behavior of dynamic containers like `std::vector` in C++.

---

## 📋 Features
- Create a dynamic array with an initial fixed capacity.
- **Automatically doubles** the capacity when more space is needed.
- Insert elements at the end of the array.
- Delete elements by index (with shifting).
- Display the current array elements.
- Proper memory management (preventing memory leaks).
- Safe handling of memory allocation failures.

---

## 📂 Project Structure
| File | Description |
|:-----|:------------|
| `dynamic_array.c` | Contains all the source code for dynamic array operations. |

---

## 🛠️ Functions Explained

### `dynamic_array* array()`
- Allocates memory for a new dynamic array.
- Initializes the size to `0` and capacity to a predefined `INITIAL_CAPACITY`.
- Allocates memory for the internal integer array.

---

### `void insertArray(dynamic_array* arr, int num)`
- Inserts a new element at the end.
- If the array is full, it automatically **doubles** the capacity using `realloc`.
- Safe handling if `realloc` fails (restores the original array).

---

### `void deleteArray(dynamic_array* arr, int index)`
- Deletes an element at the given index.
- Shifts the remaining elements to the left.
- Decreases the size by `1`.
- Checks if the index is out of range.

---

### `void displayArray(dynamic_array* arr)`
- Prints all elements currently stored in the array.

---

### `void freeArray(dynamic_array* arr)`
- Frees the dynamically allocated memory for the internal array and the dynamic array struct itself.

---

## 🚀 Example Usage

```c
int main(){
    dynamic_array* arr = array();

    insertArray(arr, 5);
    insertArray(arr, 3);
    insertArray(arr, 2);

    displayArray(arr); // Output: 5 3 2

    deleteArray(arr, 1);

    displayArray(arr); // Output: 5 2

    freeArray(arr);
    return 0;
}
