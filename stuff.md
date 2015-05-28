# Magpie Design Stuff

## Commitments

Because sometimes, you have to many good options.


**build, using GNU Make**

**completely 2d, utilising the Simple DirektMedia Layer**

**Main language is C**

I have to decide between C++ and C. Both having different good values. While
C is simple and can connect very well to python, C++ has more options for
clear programming design.

C wins, because of the ease of binding to python, using ctypes and also because
I can more easily focus on writing code.


**Scripting happens in Python**


## Basic Engine Design

The base layer of the engine is a set of c functions, that act as a box of
utility functions. Most of them may end up, simply wrapping SDL and other libs
into my owl DSL.

On top of that, a **Scene Manager** separates the different application
situations into different scenes. Basically, the Scene Manager allows for the
application to be understood as *a collection of distinct scenes, where each
scene set's up the stage, performs a thing and then cleans up and calls the
next scene after it's finished, or exits the program*

The **Renderer** knows about things that should be presented to the user and
how to put them there. It should run side by side with the Scene Manager. A
programmer writing scene code should never need to directly direct the Renderer,
instead he should be able to manipulate a scene graph, which the Renderer can
then present.

There will be at least two Renderers: a **Graphics Renderer** and a **Sound
Renderer**. All Renderers should be started and stopped outside the control
of the Scene Manager.


    +---------------+-------------------+----------------+
    | Scene Manager | Graphics Renderer | Sound Renderer |
    +---------------+-------------------+----------------+
    |                     Spark Base                     |
    +----------------------------------------------------+


[Node|children]
