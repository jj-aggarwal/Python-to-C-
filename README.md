# Python-to-C-
create a model in python and test on C++


Take any python model and use it for further steps,
1. we will have model “model.py” file saved in project folder.

we starting the next step we need to download the library from its repository on gihub. After download , 
find “keras_export” directory in the main folder of the library, and open command prompt from this directory :

2. keras model export to json
open command prompt in keras_export folder
Now, we convert the model to json file using convert_model.py . Run the following command in the command line to build model in json format :

3. python convert_model.py path/to/your/model.py CatDogNew.json
Running the command will yield “model.json” in the keras_export folder.

In this step which is so important, we prepare our Visual Studio project to use the frugally-deep library. 
First, Create new Console App and choose a name for it.

keras model to cpp json
Create new Console App project
After creating the Project, you have one cpp file opened with a main function containing “hello world” output. 
Now, It’s time to include library header file in project. Frugally-deep depends on 3 other libraries which they are also header-only and can be included without any pain. The libraries are :

Eigen
fplus
nlohmann
I gathered all of them in a zip file that you can download it with just a click here. I added the frugally-deep header files to the zip file so you don’t need to get it from source code downloaded from github.

Extract zip file and move the include folder to a place that is easy to address later. The include folder must contains all libraries like below :


the extracted folder should contain 4 libraries
Open project properties from Project menu, in left side menu click on VC++ Directories, then in right edit the Include Directories row and insert the path to the extracted include folder containing 4 libraries in the field :

keras model to cpp
Add extracted include folder address to project
As the the frugally-deep is a header-only library, it need no more configuration in project properties. So, we can go to the project’s main file and past following codes in it :
