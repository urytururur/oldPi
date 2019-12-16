from django.db import models

# Create your models here.
class Light(models.Model):
    name = models.CharField(max_length=100)
    on = models.IntegerField()
    bri = models.IntegerField()
    hue = models.IntegerField()
    sat = models.IntegerField()