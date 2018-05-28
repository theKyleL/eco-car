import socket
import struct
import csv
import time
from datetime import datetime

UDP_IP = "127.0.0.1"
UDP_PORT = 12345

STOP_SIGN_HEADER = ('Frame Number', 'X (pixels)', 'Y (pixels)', 'Radius (pixels)', 'Confidence %', 'Time (elapsed)')

sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind(('', UDP_PORT))
sock.settimeout(5)

def open_file(filename):
    datetime_tuple = datetime.now().timetuple()

    filename = filename + "_" + str(datetime_tuple[3]) + "-" + str(datetime_tuple[4]) + ".csv"

    f = open(filename, 'wb')

    try:
        writer = csv.writer(f)

        writer.writerow(STOP_SIGN_HEADER)
    except:
        f.close()
        print "Failed to open file...ending script"
        exit()

    start_time_ms = time.time()*1000

    return writer, start_time_ms, f

firt_time = True
timeout_count = 0



while True:

    # Open file if first time around
    if firt_time:
        data, addr = sock.recvfrom(1024)  # buffer size is 1024 bytes
        this_writer, this_start_time_ms, this_file = open_file(
            "StopSignRecording")  # This will append time and date to end of name and add header
        firt_time = False
        print "Started logging... (This script will automatically stop itself when it stops getting messages)"

    try:
        data, addr = sock.recvfrom(1024)  # buffer size is 1024 bytes
        (type, sequence, confidence, xloc, yloc, radius, distance) = struct.unpack("iIiiiid", data)

        elapsed_time = time.time() * 1000 - this_start_time_ms
        this_writer.writerow((sequence, xloc, yloc, radius, confidence, elapsed_time))

    except socket.timeout:
        if timeout_count is 1:
            print "Socket timed out...going down"
            this_file.close()
            break
        else:
            print "One timeout...next timeout kills script"
            timeout_count += 1

print "...Stopped logging"
