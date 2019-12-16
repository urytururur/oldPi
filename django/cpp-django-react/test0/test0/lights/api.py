from lights.models import Light
from rest_framework import viewsets, permissions
from .serializers import LightSerializer

class LightViewSet(viewsets.ModelViewSet):
    queryset = Light.objects.all()
    permission_classes = [
        permissions.AllowAny
    ]
    serializer_class = LightSerializer