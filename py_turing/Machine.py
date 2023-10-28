class Machine:
    """Класс машины
    """

    def __init__(self, string="", instructions=None):
        if instructions is None:
            instructions = {}
        self.string = string
        self.limits = 5
        self.lent = "λ" * self.limits + self.string + "λ" * self.limits
        self.instructions = instructions

    def set_word(self, word: str) -> None:
        """Установить слово в ленту машины

        Args:
            word (str): само слово
        """
        self.string = word
        self.lent = "λ" * self.limits + self.string + "λ" * self.limits

    def set_instructions(self, inst:str):
        """set_instructions

        Args:
            inst (str): строка, которая автоматически разбивается на инструкцию или инструкции, если в строке есть перенос строки
        """
        temp_inst = inst.split("\n")
        
        self.instructions = {}
        
        for i in range(0, len(temp_inst)):
            IN_STATE = temp_inst[i][0:2]
            IN_WORD = temp_inst[i][2:3]
            TO_STATE = temp_inst[i][3:5]
            TO_WORD = temp_inst[i][5:6]
            DIRECTION = temp_inst[i][6:7]

            if IN_STATE not in self.instructions:
                self.instructions[IN_STATE] = {}
            
            self.instructions[IN_STATE][IN_WORD] = {
                "replace_letter": TO_WORD,
                "direction": DIRECTION,
                "replace_state": TO_STATE
            }
        print(self.instructions)

    def start_machine(self):
        """Старт машины

        Returns:
            string: возвращает строку после обработки всех инструкций. При ошибках [неправильные инструкции, бесконечная работа машины без результата] возвращает пустую строку
        """
        position = self.limits   # Because all left symbols before limits is void
        state = "q1"             # Start state
        iterations = 0
        

        while iterations <= 100:
            try:
                letter = self.lent[position]
                replace_state = self.instructions[state][letter]["replace_state"]

                replace_letter = self.instructions[state][letter]["replace_letter"]
                direction = self.instructions[state][letter]["direction"]

                self.lent = self.lent[:position] + replace_letter + self.lent[position + 1:]
                if direction == "R":
                    position += 1
                elif direction == "L":
                    position -= 1

                iterations += 1
                
                state = replace_state
                if (state == '!') or (state == "q0"):
                    print(self.lent)    # State '!' and "q0" mean stop of handler's work
                    return self.lent
            except :
                iterations+=1
            
