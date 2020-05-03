/**
 * @file mainpage.h
 *
 * @copyright 2020 Chenxuan Liu, All rights reserved.
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_

/*! \mainpage Visual Transit System Simulator
 *
 * \section intro_sec Introduction
 * The goal of this software project is to enhance a rudimentary transit simulator
 * in which the simulation can be controlled via external configuration(without code change)
 * and be visualized within a graphics window.\n
 * \section design_sec Design
 * This project is route-based, we know how often it is that a passenger will show up at the
 * stop in each time unit. If there are more thanon bus is created, we take care of stops. Aftter
 * a bus has passed a stop, it keeps going to the next stop on the route. Buses do not make more
 * one trip through their routes, so the bus number keeps increasing. 
 * \section Discussion
 * To implement the BusFactory class, I uses the concrete one. In this way, I only need to implement 
 * 4 classes. First, generate a BusFactory class contains the generate function, then generate three 
 * different sub bus classes contain the sub constrctor and report function. Three sub bus classes are
 * SmallBus, RegularBus, amd LargeBus. They inherit all the function from Bus classes, except the report
 * function. Each sub class has its own constructor. To implement the sub constructor, I directly call the
 * default constructor in Bus class with a constant bus capacity. The advantage of using the concrete approach
 * reduce the complexity of the class structure. Also, when creating a new bus class, it will be easier than abstract
 * approach. The disadvantage of using the concrete approach is hade to exchange sub bus classes families.
 * In this iteration, it does not required to modify the sub bus families a lot, so I choose the concrete
 * approach.\n\n
 * The abstract way is easier to understand, because it is a kind of interface. It first creat an
 * AbstractBusFactory. Then, it generates three sub bus factory classes, which are named as
 * LargeBusFactory, RegularBusFactory, and SmallBusFactory. The sub bus factory classes cotain
 * the sub constructor. The implementation of constructor should be similar to the concreat approach.
 * Each constrctor creat their own bus object class.
 * Each bus object inherits from the Bus Class. The function report() is overrode in the sub bus object class.
 * The advantage of using the abstract approach is promoting consistency among sub bus object. Also, Isolation
 * concrete classes is another advantages. The abstract factory pattern helps to control the classes of
 * objects that an application creates. The disadvantage of the abstract factory is difficult to support
 * kind of products. Extending abstract factory should change the the abstract factory class and its
 * sub classes. It is more work to do compare to the concrete factory approach.\n
 * \section UserGuide
 * This project is better to run on a CSE lab machine, Linux system might work, but not guranted.\n
 * There are several steps take to run this project: 
 * 1. Open to src directory in the terminal
 * 2. Directly run make
 * 3. run "cd ..", switch the directory to project
 * 4. run "./build/bin/vis_sim 8001"
 * 5. open up a browser(Firefox/Chrome), put "http://127.0.0.1:8001/web_graphics/project.html"
 * in the address bar\n
 * Now the browser should show a map with several button.
 * After you click the "start" button, it should start generate buses.
 * There is another button “pause". After click this button, buses stop moving.
 * Click the "resume" button, the buses keeps going. 
 *\section Iteration2 Designing and Implementing the OBserverPattern
 * While implementing the observer pattern for observing information about a bus, I created three new classes. 
 * Three new class are IObserver.h,  IObservable.h, and IObserver.cc. In IObserver.h, it only has one
 * function called UpdateObserver(). It is override in my_web_server_command.cc file. This function is basically
 * print all the bus information on the right of the visualization website. In IObservable.h, I have three functions,
 * which are NotifyObservers(), ClearObservers(), and RegisterObserver(). \n
 * \image html Observer_UML.jpg "Observer Pattern Design" width=1024px
 * The most difficult part of the design is understanding the observer pattern. Understanding the relationship
 * between IObservable class and IObserver is important. Lab 14 instructions helps me a lot to understanding
 * the observer pattern. The instructions on how to implement this two classes saves me a lot of time.
 * To understand observer pattern, first you need to understand the subject and observer objects.
 * The relation between subject and observer can easily be understood as an analogy to magazine
 * subscription. The publisher of the magazine publisher, which is the subject, is in the business
 * and publishes magazines, which is data. If the observer we are interested is having a new version,
 * it will automaticaly notify us. The publish(object) does not know our information and how to use these
 * data, it just deliver to us. \n
 * \section Iteration3 Designing and Implementing the Decorator Pattern
 * For implementing the decorator pattern, there are two ways of approach. The first option of makeing
 * decorator pattern is create new subclasses for every decorator with a bus. Another option of implementing
 * decorator pattern is adding instance variables to IBus base class to represent whether or not each bus 
 * has a color decorator. \n
 * \image html Decorator_UML.png "Decorator Pattern Design" width=1024px
 * I use the second approach to implement the decorator pattern. In short, my design violates The Open-Closed
 * Principle which states that classes should be open for extension and closed for modification. In advantage, 
 * my implementation is an alternative to subclassing. Subclassing adds behavior at compile time, and the
 * change affects all instance of the original class. Decorator pattern can provide new behavior at
 * runtime for individual objects. In disadvantage, this decorator pattern can be complicated to have
 * decorators keep tract of other decorators, because we have to go back to check multiple layers of
 * the decorator chain stats to push the decorator pattern beyond its true intent. In this project,
 * our bus layer is not complicated to track, so it is easier to understand in this way. Our decorator
 * pattern exhibits temporal cohesion and informational cohesion.
 * My decorator class exhibits temporal cohesion, because decorator perform are invoked at or near the same time.
 * My decorator class exhibits informational cohesion, because the method in decorator
 * class perform are services performed by bapplication domain objects.
 * My decorator has a high cohension which means it has a low coupling. Low coupling means it is more
 * readable and easy maintence. \n
 * For the first approach to implement the decorator pattern, it is closed for extension and open for
 * modification. In advantage, this approach is valuable when the decorate pattern is not complex. It
 * is easy to implement. In disadvantage, once there are more decorate requirements, it will become complex.
 * And it is nightmare for maintence. This approach has a high coupling and low cohension. Every function
 * in decorate class are not related. \n
 * In this iteration, the most difficult part is to understanding the simulation statistics and using
 * template pattern to implement the observer pattern for both bus and stop class. Lab 16 instruction
 * helped me to solve the statistic problem. Zybook material helps me understand template pattern.
 * 
 */

#endif  // SRC_MAINPAGE_H_
