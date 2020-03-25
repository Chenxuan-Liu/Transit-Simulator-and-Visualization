/**
 * @file mainpage.h
 *
 * @copyright 2020 Chenxuan Liu, All rights reserved.
 */

#ifndef MAINPAGE_H_
#define MAINPAGE_H_

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
 */

#endif  // MAINPAGE_H_
