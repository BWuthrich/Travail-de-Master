# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/ConfigNtrip.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConfigNtrip(type):
    """Metaclass of message 'ConfigNtrip'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('xsens_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'xsens_msgs.msg.ConfigNtrip')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__config_ntrip
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__config_ntrip
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__config_ntrip
            cls._TYPE_SUPPORT = module.type_support_msg__msg__config_ntrip
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__config_ntrip

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConfigNtrip(metaclass=Metaclass_ConfigNtrip):
    """Message class 'ConfigNtrip'."""

    __slots__ = [
        '_host',
        '_port',
        '_mountpoint',
        '_username',
        '_password',
        '_rtcm_timer',
    ]

    _fields_and_field_types = {
        'host': 'string',
        'port': 'int16',
        'mountpoint': 'string',
        'username': 'string',
        'password': 'string',
        'rtcm_timer': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.host = kwargs.get('host', str())
        self.port = kwargs.get('port', int())
        self.mountpoint = kwargs.get('mountpoint', str())
        self.username = kwargs.get('username', str())
        self.password = kwargs.get('password', str())
        self.rtcm_timer = kwargs.get('rtcm_timer', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.host != other.host:
            return False
        if self.port != other.port:
            return False
        if self.mountpoint != other.mountpoint:
            return False
        if self.username != other.username:
            return False
        if self.password != other.password:
            return False
        if self.rtcm_timer != other.rtcm_timer:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def host(self):
        """Message field 'host'."""
        return self._host

    @host.setter
    def host(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'host' field must be of type 'str'"
        self._host = value

    @property
    def port(self):
        """Message field 'port'."""
        return self._port

    @port.setter
    def port(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'port' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'port' field must be an integer in [-32768, 32767]"
        self._port = value

    @property
    def mountpoint(self):
        """Message field 'mountpoint'."""
        return self._mountpoint

    @mountpoint.setter
    def mountpoint(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mountpoint' field must be of type 'str'"
        self._mountpoint = value

    @property
    def username(self):
        """Message field 'username'."""
        return self._username

    @username.setter
    def username(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'username' field must be of type 'str'"
        self._username = value

    @property
    def password(self):
        """Message field 'password'."""
        return self._password

    @password.setter
    def password(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'password' field must be of type 'str'"
        self._password = value

    @property
    def rtcm_timer(self):
        """Message field 'rtcm_timer'."""
        return self._rtcm_timer

    @rtcm_timer.setter
    def rtcm_timer(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rtcm_timer' field must be of type 'float'"
        self._rtcm_timer = value
