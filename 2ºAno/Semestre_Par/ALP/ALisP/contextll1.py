class ContextLL1:
    def __init__(self, word):
        self.word = word
        self.pos = 0

    def is_complete(self):
        return self.pos >= len(self.word)

    def next(self):
        if not self.is_complete
