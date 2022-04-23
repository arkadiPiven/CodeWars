import threading


class Validator:
    scheduler = []
    threads = []
    num_of_threads = 1
    solution = None
    total_jobs_done = 0
    lock = threading.Lock()
    all_jobs_done = threading.Condition(lock)
    scheduler_empty = threading.Condition(lock)

    def __init__(self, solution, num_of_threads):
        self.solution = solution
        self.num_of_threads = num_of_threads
        for i in range(self.num_of_threads):
            th = threading.Thread(target=self.get_job)
            self.threads.append(th)
            self.threads[i].start()

    def get_job(self):
        while True:
            self.lock.acquire()
            while not self.scheduler:
                print("Going to sleep")
                self.scheduler_empty.wait()
            job = self.scheduler.pop(0)
            self.lock.release()
            ret_value = job.execute(self.solution)
            if ret_value == 1:
                return

    def schedule_job(self, job):
        self.lock.acquire()
        self.scheduler.append(job)
        print(len(self.scheduler))
        if len(self.scheduler) == 1:
            self.scheduler_empty.notify()
        self.lock.release()

    def solve(self):
        print('Inside solve')
        for i in range(0, 9):
            self.schedule_job(self.Row(i))
            self.schedule_job(self.Column(i))
            self.schedule_job(self.Block(i))
        for i in range(self.num_of_threads):
            self.schedule_job(self.Cyanide())
        for thread in self.threads:
            thread.join()

    class Job:
        start_index = 0

        def __init__(self, start_index):
            self.start_index = start_index

        def execute(self, solution):
            return

    class Row(Job):

        def __init__(self, start_index):
            super().__init__(start_index)

        def execute(self, solution):
            dictionary = []
            for j in range(9):
                if solution[self.start_index][j] in dictionary:
                    return False
                dictionary[solution[self.start_index][j]] = 1

    class Column(Job):

        def __init__(self, start_index):
            super().__init__(start_index)

        def execute(self, solution):
            dictionary = []
            for j in range(9):
                if solution[j][self.start_index] in dictionary:
                    return False
                dictionary[solution[self.start_index][j]] = 1

    class Block(Job):

        def __init__(self, start_index):
            super().__init__(start_index)

        def execute(self, solution):
            dictionary = []
            for j in range(3):
                for i in range(3):
                    if solution[int(self.start_index / 3) * 3 + j][self.start_index % 3 + i] in dictionary:
                        return False
                    dictionary[solution[int(self.start_index / 3) * 3 + j][self.start_index % 3 + i]] = 1

    class Cyanide:

        def __init__(self):
            return

        @staticmethod
        def execute(solution):
            return 1


def valid_solution(solution):
    validator = Validator(solution, 1)
    validator.solve()
    return


def main():
    solution_1 = [
        [5, 3, 4, 6, 7, 8, 9, 1, 2],
        [6, 7, 2, 1, 9, 5, 3, 4, 8],
        [1, 9, 8, 3, 4, 2, 5, 6, 7],
        [8, 5, 9, 7, 6, 1, 4, 2, 3],
        [4, 2, 6, 8, 5, 3, 7, 9, 1],
        [7, 1, 3, 9, 2, 4, 8, 5, 6],
        [9, 6, 1, 5, 3, 7, 2, 8, 4],
        [2, 8, 7, 4, 1, 9, 6, 3, 5],
        [3, 4, 5, 2, 8, 6, 1, 7, 9]
    ]

    solution_2 = [
        [5, 3, 4, 6, 7, 8, 9, 1, 2],
        [6, 7, 2, 1, 9, 0, 3, 4, 8],
        [1, 0, 0, 3, 4, 2, 5, 6, 0],
        [8, 5, 9, 7, 6, 1, 0, 2, 0],
        [4, 2, 6, 8, 5, 3, 7, 9, 1],
        [7, 1, 3, 9, 2, 4, 8, 5, 6],
        [9, 0, 1, 5, 3, 7, 2, 1, 4],
        [2, 8, 7, 4, 1, 9, 6, 3, 5],
        [3, 0, 0, 4, 8, 1, 1, 7, 9]
    ]

    assert (valid_solution(solution_1))
    assert (not valid_solution(solution_2))

    return


if __name__ == "__main__":
    main()
