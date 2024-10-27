from django.db import models

# Create your models here.
class planets(models.Model):
    name = models.CharField(
        max_length = 64,
        unique = True,
        null = False,
    )
    climate = models.CharField(
        null = True,
    )
    diameter = models.IntegerField(
        null = True,
    )
    orbital_period = models.IntegerField(
        null = True,
    )
    population = models.BigIntegerField(
        null = True,
    )
    rotation_period = models.IntegerField(
        null = True,
    )
    surface_water = models.FloatField(
        null = True,
    )
    terrain = models.CharField(
        null = True,
    )

    created = models.DateTimeField(auto_now_add = True)
    updated = models.DateTimeField(auto_now = True)

    def __str__(self):
        return self.name.__str__()

class people(models.Model):
    name = models.CharField(
        max_length = 64,
        null = False,
    )
    birth_year = models.CharField(
        max_length = 32,
        null = True,
    )
    gender = models.CharField(
        max_length = 32,
        null = True,
    )
    eye_color = models.CharField(
        max_length = 32,
        null = True,
    )
    hair_color = models.CharField(
        max_length = 32,
        null = True,
    )
    height = models.IntegerField(
        null = True,
    )
    mass = models.FloatField(
        null = True,
    )
    homeworld = models.ForeignKey(planets, on_delete = models.CASCADE, null = True)

    created = models.DateTimeField(auto_now_add=True)
    updated = models.DateTimeField(auto_now=True)

    def __str__(self):
        return self.name.__str__()

