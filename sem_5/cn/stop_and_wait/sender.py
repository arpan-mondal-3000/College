import socket
import time

# PARAMETERS
FRAME_SIZE = 8              # bytes
PROP_DELAY = 2              # seconds
TIMEOUT = 5                 # seconds
TOTAL_DATA = "HELLO_STOP_AND_WAIT_PROTOCOL"

HOST = "127.0.0.1"
PORT = 1234

def sender():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    s.settimeout(TIMEOUT)

    seq_no = 0
    index = 0

    print("Sender started...\n")

    while index < len(TOTAL_DATA):
        frame = TOTAL_DATA[index:index + FRAME_SIZE]
        packet = f"{seq_no}:{frame}"

        try:
            print(f"Sending Frame → Seq:{seq_no}, Data:'{frame}'")
            s.send(packet.encode())

            time.sleep(PROP_DELAY)   # propagation delay

            ack = s.recv(1024).decode()

            if ack == f"ACK:{seq_no}":
                print(f"ACK received for Seq:{seq_no}\n")
                seq_no = 1 - seq_no
                index += FRAME_SIZE
            else:
                print("Wrong ACK received, retransmitting...\n")

        except socket.timeout:
            print("Timeout! Retransmitting frame...\n")

    s.send(b"END")
    s.close()
    print("Transmission Complete.")

if __name__ == "__main__":
    sender()
