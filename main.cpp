#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
// Player health variables
int player_health = 100;
//-------------------------------------------------------------------------------------
//variables for player data
//these are variables for the resources collected by the player
int player_wood = 0;
int player_stone = 0;
int player_iron = 0;
int player_apple = 0;
//these 3 are the variables for the 3 craftable items
//there can only be 3 craftable items. 
int player_pickaxe = 0;
int player_sword = 0;
int player_cooked_apple = 0;
// World resources---------------------------------------------------------------------
//these are the variable of how many resources the current word has 
int world_wood = 0;
int world_stone = 0;
int world_iron = 0;
int world_apple = 0;
// Recipe variables--------------------------------------------------------------------
//the program will read and put needed inputs into these variables, these are the required 
//materials that the program needs, because arrays and vectors arent allowed
//this is what hold the set amount of items. the requirements can change but its all just reading
//from the file
int pickaxe_wood = 0;
int pickaxe_stone = 0;
int sword_iron = 0;
int sword_wood = 0;
int cooked_apple_apple = 0;
// Load resources from resources.txt---------------------------------------------------
ifstream resourcesFile("resources.txt");
ifstream recipesFile("recipes.txt");
if (!resourcesFile) {
    //read the frile from 
    cout << "Error: Could not open resources.txt." << endl;
    return 1;
}
if(!recipesFile){
    cout << "Error: Could not open recipes.txt" << endl;
}
//my code goes here
//step 1 read from the resources file and input them into the variables
//the number of resources will always stay the same
//but the amount of each individual resource will change and that is why it is input
//instead of hardcoding it.


string resource_1 = "";
int resource_1_amount = 0;

string resource_2 = "";
int resource_2_amount = 0;

string resource_3 = "";
int resource_3_amount = 0;

string resource_4 = "";
int resource_4_amount = 0;


//loop that will read all values from the resources file
//
int current_resource_read_tally = 1;
bool validRun = true;
while(validRun){
    switch(current_resource_read_tally){
        case 1:
            if(!(resourcesFile >> resource_1 >> resource_1_amount)){
                if(resourcesFile.eof()){
                    validRun = false;
                    break;
                }  
                cout << "Error: Invalid item amount deteced in file" << endl;
            }
            if(resource_1_amount < 0){
                validRun = false;
            }
            current_resource_read_tally++;
            break;
        case 2:
            if(!(resourcesFile >> resource_2 >> resource_2_amount)){
                if(resourcesFile.eof()){
                     validRun = false;
                    break;
                }  
                cout << "Error: Invalid item amount deteced in file" << endl;
            }
            if(resource_2_amount < 0){
                validRun = false;
            }
            current_resource_read_tally++;
            break;
        case 3:
            if(!(resourcesFile >> resource_3 >> resource_3_amount)){
                if(resourcesFile.eof()){
                    validRun = false;
                    break;
                }  
                cout << "Error: Invalid item amount deteced in file" << endl;
            }
            if(resource_2_amount < 0){
                validRun = false;
            }
            current_resource_read_tally++;
            break;
        case 4:
            if(!(resourcesFile >> resource_4 >> resource_4_amount)){
                if(resourcesFile.eof()){
                    validRun = false;
                    break;
                }  
                cout << "Error: Invalid item amount deteced in file" << endl;
            }
            if(resource_1_amount < 0){
                validRun = false;
            }
            current_resource_read_tally++;
            break;
    }
    if(current_resource_read_tally == 5){
        break;
    }
}

//testing for the input, it works
cout << resource_1 << " " << resource_1_amount << endl;
cout << resource_2 << " " << resource_2_amount << endl;
cout << resource_3 << " " << resource_3_amount << endl;
cout << resource_4 << " " << resource_4_amount << endl;

//-------------------------------------------------------------------------------------------------------------------------------------
//step 2. read from the recipes file and input the amounts into the int variables. the name seems to not
//matter as it is expected from the program and no new names will be input into it. 

string recipe_one_name = "";

string recipe_one_material_one = "";
int recipe_one_material_one_amount = 0;

string recipe_one_material_two = "";
int recipe_one_material_two_amount = 0;



//recipesFile   is the name of the fstream variable
bool is_empty = false;
string temporary_line = "";
bool endFile = false;
//loop runs 3 times, there are 3 recipes and there always will be
for(int i = 0; i < 3; i++){
    //this if statement will check which of the recipes is being read. there will be 3 recipes
    //so there are 3 if statement checks of the for loop value
    if(recipesFile.eof()){
        break;
    }

    //if check for the pickaxe
    if(i == 0){
        for(int k = 1; k < 4; k++){
            if(k == 1){
                if(!getline(recipesFile, recipe_one_name)){
                    break;
                }
                if(recipe_one_name == ""){
                    break;
                }
            }
            else if(k == 2){
                if(!getline(recipesFile, temporary_line)){
                    break;
                }
                if(temporary_line == ""){
                    break;
                }
                recipe_one_material_one = temporary_line.substr(0, temporary_line.find(' '));
                recipe_one_material_one_amount = stoi(temporary_line.substr(temporary_line.find(' ') + 1));
            }
            else if(k == 3){
                if(!getline(recipesFile, temporary_line)){
                    break;
                }
                if(temporary_line == ""){
                    break;
                }
                recipe_one_material_two = temporary_line.substr(0, temporary_line.find(' '));
                recipe_one_material_two_amount = stoi(temporary_line.substr(temporary_line.find(' ') + 1));
                break;
            }
        }
    }else if(i == 1){

    }else if(i == 2){

    }
}
cout << recipe_one_name << endl;
cout << recipe_one_material_one << " " << recipe_one_material_one_amount << endl;
cout << recipe_one_material_two << " " << recipe_one_material_two_amount << endl;


    return 0;
}
