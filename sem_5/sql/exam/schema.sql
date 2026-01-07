-- Phase 1: Table creation

CREATE TABLE instructors(
    instructor_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    department VARCHAR(100) NOT NULL
);

CREATE TABLE courses(
    course_id INT PRIMARY KEY AUTO_INCREMENT,
    title TEXT NOT NULL,
    credits INT NOT NULL,
    instructor_id INT NOT NULL,
    FOREIGN KEY (instructor_id) REFERENCES instructors(instructor_id)
);

CREATE TABLE students(
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    enrollment_year YEAR NOT NULL,
    major VARCHAR(100) NOT NULL
);

CREATE TABLE enrollments(
    enrollment_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT NOT NULL,
    course_id INT NOT NULL,
    grade ENUM('A','B','C'),
    FOREIGN KEY (student_id) REFERENCES students(student_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
);

-- Phase 2: Data insertion

INSERT INTO instructors(
    instructor_id,
    name,
    department
)
VALUES
    (1, 'Dr. Alice Wong', 'Computer Science'),
    (2, 'Prof. Bob Smith', 'Mathematics'),
    (3, 'Dr. Carol Davis', 'Physics'),
    (4, 'Dr. Raj Patel', 'Computer Science'),
    (5, 'Prof. Emily White', 'History');

INSERT INTO courses(
    course_id,
    title,
    credits,
    instructor_id
)
VALUES
    (101, 'Intro to CS', 4, 1),
    (102, 'Calculus I', 3, 2),
    (103, 'Mechanics', 4, 3),
    (104, 'Data Structures', 4, 1),
    (105, 'Algorithms', 4, 4),
    (106, 'Linear Algebra', 3, 2),
    (107, 'World History', 3, 5),
    (108, 'Quantum Physics', 5, 3);

INSERT INTO students(
    student_id,
    name,
    enrollment_year,
    major
)
VALUES
    (1, 'Liam Johnson', 2023, 'Computer Science'),
    (2, 'Olivia Williams', 2023, 'Mathematics'),
    (3, 'Noah Brown', 2024, 'Physics'),
    (4, 'Emma Davis', 2024, 'Computer Science'),
    (5, 'James Wilson', 2024, 'History'),
    (6, 'Sophia Taylor', 2025, 'Undeclared');

INSERT INTO enrollments(
    enrollment_id,
    student_id,
    course_id,
    grade
)
VALUES
    (1, 1, 101, 'A'),
    (2, 1, 102, 'B'),
    (3, 2, 102, 'A'),
    (4, 3, 103, 'B'),
    (5, 1, 104, 'A'),
    (6, 4, 101, 'B'),
    (7, 4, 105, 'A'),
    (8, 5, 107, 'A'),
    (9, 2, 106, 'C'),
    (10, 3, 108, 'B');