import socket
import time

# PARAMETERS
PROP_DELAY = 2   # seconds

HOST = "127.0.0.1"
PORT = 1234

def receiver():
    r = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    r.bind((HOST, PORT))
    r.listen(1)

    print("Receiver waiting for connection...")
    conn, addr = r.accept()
    print("Connected to sender\n")

    expected_seq = 0
    received_data = ""

    while True:
        packet = conn.recv(1024).decode()

        if packet == "END":
            break

        seq_no, data = packet.split(":", 1)

        print(f"Received Frame → Seq:{seq_no}, Data:'{data}'")

        if int(seq_no) == expected_seq:
            received_data += data
            print("Frame accepted")
            expected_seq = 1 - expected_seq
        else:
            print("Duplicate frame detected")

        time.sleep(PROP_DELAY)  # propagation delay
        ack = f"ACK:{seq_no}"
        conn.send(ack.encode())
        print(f"ACK sent → {ack}\n")

    print("\nFinal Received Data:", received_data)
    conn.close()
    r.close()

if __name__ == "__main__":
    receiver()
