
########
Examples
########

The following is a list of examples and their purpose.
These examples exist in all available example languages.

.. list-table:: Example purpose
   :header-rows: 1
   :widths: 10 20 70

   * - No.
     - Name
     - What it teaches
   * - 00
     - list-devices
     - Shows what cameras there are and how to identify them
   * - 01
     - list-properties
     - Shows the properties of a camera and their settings (range, current value, etc.)
   * - 02
     - set-property
     - Shows how to set a specific property
   * - 03
     - live-stream
     - Delivers live-image stream from the camera
   * - 04
     - list-formats
     - Lists what formats the camera offers
   * - 05
     - set-format
     - Sets the camera to a specific format
   * - 06
     - softwaretrigger
     - Triggers single images - instead of a continuous image stream
   * - 07
     - appsink
     - Receives images in an application instead of just showing them.
   * - 08
     - save-stream
     - Stores a stream in a file.
   * - 09
     - device-lost
     - Receives device-lost and other messages and react to them
   * - 10
     - metadata
     - Read meta information like is-damaged, camera capture time, etc.
       Currently only in available in C.
   * - 11
     - device-state
     - Save and load JSON device state

.. _examples_further:

Further Examples
================

For extended examples, look through the examples repository.

https://github.com/TheImagingSource/Linux-tiscamera-Programming-Samples

It contains examples on how to interact with OpenCV, ROS, GUI toolkits and much more.
