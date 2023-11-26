# GameEngine
Making a game engine... idk how this will go. 

Changes to make if used:

use 'git submodule' feature to copy the glfw library from MY Repo since it contains a premake file needed to run the code properly. Of course, make this go into the global-libs folder to make the directory right. 


Libraries used: Premake, SPDLogging, GLFW, Dear ImGUI, GLAD, and finally Open GSL for graphics math. However, I will be creating a custom math library for my own purposes and use it in this when I finish- mostly the used functions will stay the same, but I'll add more functions in general 

Currently privately working on an alternative to SPD logging, but mostly going to work once the base window and features are up and running. 
Will be working on a Math Lib that is SIMD - 😢


GOAL: The entire point of this engine isn't to be the best or fastest. That is up to unity or unreal or something more commercial. My goal is to make this as customizable is possible as much as I can. This includes custom scripting with languages of choice, various render APIs, a custom physics engine(built-in or PhysX or something like that), and custom AI choices.


At the current point in time, there is a pseudo-camera system in place using glm::perspective. This is rather makeshift and I will work on making it a bit more interactive to post here. 

https://www.youtube.com/watch?v=3i7z2MI6Npg&list=PLri1_ogVec6Xvi8F6lb20kgSL4AA3kIDD&index=5&t=3s&ab_channel=RaghavIyer - LINK TO WORKING CAMERA DEMONSTRATION
