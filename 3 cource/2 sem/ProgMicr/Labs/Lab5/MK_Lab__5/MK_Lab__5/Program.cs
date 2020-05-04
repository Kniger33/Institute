using System;
using System.IO.Ports;

namespace MK_Lab__5
{
    class Program
    {
        static void Main(string[] args)
        {
            SerialPort _serialPort;

            try
            {
                // настройки порта
                _serialPort = new SerialPort("COM1", 9600, Parity.None, 8, StopBits.One);
                _serialPort.Handshake = Handshake.None;
                _serialPort.WriteTimeout = 1000;
                _serialPort.Open();
            }
            catch (Exception e)
            {
                Console.WriteLine("ERROR: невозможно открыть порт:" + e.ToString());
                return;
            }

            bool flag = true;

            while (flag)
            {
                Console.WriteLine("Действие:");
                Console.WriteLine("1 - вкл/выкл");
                Console.WriteLine("2 - режим");
                Console.WriteLine("3 - скорость");
                Console.WriteLine("0 - выход");

                string operand = Console.ReadLine();

                switch (operand)
                {
                    case "1":
                    {
                            try
                            {
                                if (!(_serialPort.IsOpen))
                                    _serialPort.Open();
                                _serialPort.Write("1");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine("Error opening/writing to serial port :: "
                                                + ex.Message, "Error!");
                            }
                            break;
                    }
                    case "2":
                    {
                            try
                            {
                                if (!(_serialPort.IsOpen))
                                    _serialPort.Open();
                                _serialPort.Write("2");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine("Error opening/writing to serial port :: "
                                                + ex.Message, "Error!");
                            }
                            break;
                    }
                    case "3":
                    {
                            try
                            {
                                if (!(_serialPort.IsOpen))
                                    _serialPort.Open();
                                _serialPort.Write("3");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine("Error opening/writing to serial port :: "
                                                + ex.Message, "Error!");
                            }
                            break;
                    }
                    case "0":
                    {
                        flag = false;
                        return;
                    }
                }
            }

            _serialPort.Close();
        }
    }
}