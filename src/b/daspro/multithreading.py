import threading
import time
import os

# Thread 1: simulasi video stream
def video_stream():
    while True:
        print("[VIDEO] Receiving video frame...")
        time.sleep(2)

# Thread 2: simulasi telemetry stream
def telemetry_stream():
    path = os.path.join(os.path.dirname(__file__), "telemetry.txt")
    with open(path, "r") as file:
        for line in file:
            print("[TELEMETRY]", line.strip())
            time.sleep(3)

# Membuat thread
video_thread = threading.Thread(target=video_stream)
telemetry_thread = threading.Thread(target=telemetry_stream)

# Menjalankan thread
video_thread.start()
telemetry_thread.start()

# Program utama berjalan 10 detik
time.sleep(10)
print("Main program finished.")
