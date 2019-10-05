class Processor:
    data = dict

    def __init__(self, **kwargs):
        self.data = kwargs

    def __str__(self):
        return f"\nArticle: {self.data.get('article')}\n"     \
                f"Producer: {self.data.get('producer')}\n"  \
                f"Name: {self.data.get('name')}\n"          \
                f"Cores count: {self.data.get('cores')}\n"  \
                f"Frequency: {self.data.get('frequency')}\n"\
                f"Price: {self.data.get('price')}\n"

    @staticmethod
    def attributes():
        return ['article', 'producer', 'name',
                'cores', 'frequency', 'price']

    def __dict__(self):
        return {
            'article': self.data.get('article'),
            'producer': self.data.get('producer'),
            'name': self.data.get('name'),
            'cores': self.data.get('cores'),
            'frequency': self.data.get('frequency'),
            'price': self.data.get('price'),
        }
