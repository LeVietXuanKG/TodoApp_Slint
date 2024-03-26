# TodoApp_Slint
Use Slint C++ to build todo app
You can test TodoApp by open this **./build/Debug/my_application.exe**
![TodoApp](image/TodoApp.png)
* This App has **3 functions:** Add New Entry, Check Todo Lists, Remove Done Item use C++ API
* **Src C++: src/Main.cpp** 
* **Src Slint: ui/MySlint.slint**
# Learn to coding it
## **1.Import Library and create Struct**
![Todo](image/Todo1.png)

## **2.Create Callback(functions) and lists**
![Todo](image/Todo2.png)

## **3.Create ui for add List**
![Todo](image/Todo3.png)
![Todo](image/Todo4.png)

## **4.Create ui for List**
![Todo](image/Todo5.png)
![Todo](image/Todo6.png)

## **5.Create Remove function and PopupWindow to confirm**
![Todo](image/Todo7.png)

![Todo](image/Todo8.png)

![Todo](image/Todo9.png)

![Todo](image/Todo10.png)

## **6.Use C++ for Init Program**
![C++](image/c1.png)
* Use file TodoList.txt to save TodoList

![C++](image/c3.png)
* Convert slint::SharedString to std::string and std::string to slint::SharedString

![C++](image/c2.png)
* Use Vector Model to set todo_model in slint(list todo)

## **7.Use C++ for define callback**
![C++](image/c4.png)

## **8.Write function for app**
![C++](image/c5.png)

![C++](image/c6.png)

![C++](image/c7.png)
