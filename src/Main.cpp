#include <MySlint.h>
#include <fstream>
#include <vector>
using namespace std;

const int MaxList = 500;
string str;
vector<slint::SharedString> str1;
vector<bool> CheckTodo;
int n;

slint::SharedString to_shared_string(const string& stdString){
    return slint::SharedString(stdString);
}

string to_std_string(const slint::SharedString& ShaStr){
    return string(ShaStr);
}
void SaveFile(){
    ofstream fo;
    fo.open("../../TodoList/TodoList.txt");
    fo << n << endl;
    for(auto x : str1){
        fo << to_std_string(x) << endl;
    }
    for(auto x: CheckTodo){
        fo << x << endl;
    }
    fo.close();
}
void ApplyChange(auto& todo_app){
    vector<TodoItem> TodoLists;
        for(int i = 0; i < n; i++){
            TodoLists.push_back(TodoItem{str1[i], CheckTodo[i]});
        }
        auto GetItem = std::make_shared<slint::VectorModel<TodoItem>>(TodoLists);
        todo_app->set_todo_model(GetItem);
}
void SetUp(auto& todo_app){
    ifstream fi;
    fi.open("../../TodoList/TodoList.txt", ios::app);
    fi >> n;
    fi.ignore();
    for(int i = 0; i < n; i++){
        getline(fi, str);
        str1.push_back(to_shared_string(str));
    }
    for(int i = 0; i < n; i++){
        bool x;
        fi >> x;
        CheckTodo.push_back(x);
    }
    fi.close();

    
}

void AddTodoItem(slint::SharedString st){
    str1.push_back(st);
    n++;
    CheckTodo.push_back(false);
    SaveFile();
}

void RemoveItemDone(){
    int NumChecked = 0;
    vector<int> PosToDel;
    for(int i = 0; i<n; i++){
        if(CheckTodo[i]){
            NumChecked++;
            PosToDel.push_back(i);
        }
    }
    n -= NumChecked;
    reverse(PosToDel.begin(),PosToDel.end());
    for(auto x : PosToDel){
        str1.erase(str1.begin() + x);
        CheckTodo.erase(CheckTodo.begin() + x);
    }
    SaveFile();
}
void CheckBox(int index){
    CheckTodo[index] = !CheckTodo[index];
    SaveFile();
    return;
}
int main() {
    auto todo_app = MainWindow::create();
    SetUp(todo_app);
    ApplyChange(todo_app);
    todo_app->on_todo_added([&](slint::SharedString st){
        AddTodoItem(st);
        ApplyChange(todo_app);
    });

    todo_app->on_change_element([&](int index){
        CheckBox(index);
        ApplyChange(todo_app);
    });
    todo_app->on_remove_done([&]{
        RemoveItemDone();
        ApplyChange(todo_app);
    });
    todo_app->run();
}
