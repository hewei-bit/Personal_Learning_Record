#!/usr/bin/python3

from PyQt5.QtCore import QTimer, QByteArray, QIODevice
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo

from PyQt5.QtWidgets import *
import sys

from SaveData import SaveData
from SaveData import AutoSave

class SerialWidget(QWidget):

    def __init__(self, parent=None):
        super().__init__(parent)

        self.__data = QByteArray()
        self.__serial = QSerialPort()
        self.__timer = QTimer(self)

        for info in QSerialPortInfo.availablePorts():
            if info.description() == "USB-SERIAL CH340":
                self.__serial = QSerialPort(info)
                print(self.__serial.portName())
                break

        self.__serial.readyRead.connect(self.__read_data)
        self.__timer.timeout.connect(self.__timer_update_com)

        self.__temperature = 0
        self.__humidity = 0
        self.__co2 = 0
        self.__tvoc = 0
        self.__pm25 = 0
        self.__pm10 = 0
        self.__o2 = 0

        if self.__serial.open(QIODevice.ReadWrite):
            print("open success")
        else:
            print("open fail")
        self.__auto_save_thread = AutoSave(self)
        self.__auto_save_thread.start()

    def closeEvent(self, QCloseEvent):
        self.__auto_save_thread.kill()
        super().closeEvent(QCloseEvent)

    def __read_data(self):
        self.__timer.start(40)
        self.__data.append(self.__serial.readAll())

    def __timer_update_com(self):
        self.__timer.stop()
        length = self.__data.length()
        i = 0
        while i < length:
            num = ord(self.__data[i])
            if num == 116:
                num = ord(self.__data[i + 1])
                self.__temperature = num
                i += 1
                print("temperature:" + str(self.__temperature))
            elif num == 116 - ord('t') + ord('h'):
                num = ord(self.__data[i + 1])
                self.__humidity = num
                i += 1
                print("humidity:" + str(self.__humidity))
            elif num == 116 - ord('t') + ord('c'):
                num = ord(self.__data[i + 1]) * 258 + ord(self.__data[i + 2])
                self.__co2 = num
                i += 2
                print("CO2:" + str(self.__co2))
                num = ord(self.__data[i + 1]) * 258 + ord(self.__data[i + 2])
                self.__tvoc = num
                i += 2
                print("TVOC:" + str(self.__tvoc))
            elif num == 116 - ord('t') + ord('o'):
                num = ord(self.__data[i + 1]) * 258 + ord(self.__data[i + 2])
                num = num * (3300 / 4096) / 100
                num = round(num, 3)
                self.__o2 = num
                i += 2
                print("O2:" + str(self.__o2) + "%")
            elif num == 116 - ord('t') + ord('p'):
                num = ord(self.__data[i + 1]) * 258 + ord(self.__data[i + 2])
                num /= 10
                self.__pm25 = num
                i += 2
                print("PM2.5:" + str(self.__pm25))
                num = ord(self.__data[i + 1]) * 258 + ord(self.__data[i + 2])
                num /= 10
                self.__pm10 = num
                i += 2
                print("PM10:" + str(self.__pm10))
            i += 1
        self.__data.clear()

    def get_temperature(self):
        return self.__temperature

    def get_humidity(self):
        return self.__humidity

    def get_co2(self):
        return self.__co2

    def get_tvoc(self):
        return self.__tvoc

    def get_pm25(self):
        return self.__pm25

    def get_pm10(self):
        return self.__pm10

    def get_o2(self):
        return self.__o2


if __name__ == '__main__':
    app = QApplication(sys.argv)
    my_serial = SerialWidget()
    my_serial.show()
    sys.exit(app.exec_())