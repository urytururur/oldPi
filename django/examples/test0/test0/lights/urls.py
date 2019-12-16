from rest_framework import routers
from .api import LightViewSet

router = routers.DefaultRouter()
router.register('api/lights', LightViewSet, 'lights')

urlpatterns = router.urls