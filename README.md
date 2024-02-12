# Hazard Detection System

This project is for (CSE211:Introduction to Embedded Systems) course at Faculty of Engineering Ain Shams University. It is a comprehensive hazard detection system consisting of two main components: a sender unit and a receiver unit. The sender unit utilizes Tiva C microcontroller along with various sensors to detect gas leaks, fires, window intrusions, and door openings. Upon detection of any hazard, it sends a signal via Li-Fi communication to the receiver unit.

## Sender Unit Features:
- **Tiva C Microcontroller**: Utilized as the main control unit for the sender unit.
- **Gas and Fire Sensors**: Fume sensors are employed to detect gas leaks and fires.
- **Magnetic Hall Sensor**: Detects intrusion through windows.
- **Ultrasonic Sensor**: Detects door openings.
- **Bluetooth Module**: Sends hazard notifications to smartphones.
- **Laser Diode**: Sends signals via Li-Fi technology to the receiver unit.

## Receiver Unit Features:
- **Arduino Uno Microcontroller**: Controls the receiver unit.
- **Lamp Indicator**: Flashes when a hazard is detected.
- **Buzzer**: Provides audible alerts for detected hazards.
- **LCD Display**: Displays messages regarding the detected hazard.
- **Mute Button**: Allows users to mute the alarm; automatically unmutes after 5 seconds.
- **Laser Diode Receiver (LSDR)**: Receives signals sent by the sender unit via Li-Fi.

## System Controls:
- **Start/Stop Buttons**: Control the operation of the entire system.

## Additional Resources:
- [Project Documentation](https://drive.google.com/file/d/1mSzgsOncTHhjm9P1KVLquHjqN82NWDgf/view?usp=sharing): Detailed documentation outlining the project's components, circuit diagrams, and code explanations.
- [Project Video](https://www.youtube.com/watch?v=awd9nEAME8g): Video demonstration showcasing the project in action.

## Getting Started:
To set up and run the hazard detection system, please refer to the documentation provided in the link above. Ensure all components are correctly connected and configured before powering on the system.

## Contributors:
- [Youssef Mahmoud](https://github.com/xYoussefMahmoudx)
- [Anass Zikry](https://github.com/anass-zikry)
- [Ahmed Khaled](https://github.com/Ahmedkhaledd1)
- [Ahmed Galal](https://github.com/ABarakat27)
- [Mahmoud Talaat](https://github.com/Mtalaat432)
  


