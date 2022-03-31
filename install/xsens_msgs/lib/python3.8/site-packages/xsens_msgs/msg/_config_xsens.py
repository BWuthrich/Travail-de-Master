# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/ConfigXsens.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConfigXsens(type):
    """Metaclass of message 'ConfigXsens'."""

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
                'xsens_msgs.msg.ConfigXsens')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__config_xsens
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__config_xsens
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__config_xsens
            cls._TYPE_SUPPORT = module.type_support_msg__msg__config_xsens
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__config_xsens

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConfigXsens(metaclass=Metaclass_ConfigXsens):
    """Message class 'ConfigXsens'."""

    __slots__ = [
        '_configuration',
        '_baudrate',
        '_port_name',
        '_rtcm_refresh_dist',
    ]

    _fields_and_field_types = {
        'configuration': 'string',
        'baudrate': 'uint32',
        'port_name': 'string',
        'rtcm_refresh_dist': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.configuration = kwargs.get('configuration', str())
        self.baudrate = kwargs.get('baudrate', int())
        self.port_name = kwargs.get('port_name', str())
        self.rtcm_refresh_dist = kwargs.get('rtcm_refresh_dist', int())

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
        if self.configuration != other.configuration:
            return False
        if self.baudrate != other.baudrate:
            return False
        if self.port_name != other.port_name:
            return False
        if self.rtcm_refresh_dist != other.rtcm_refresh_dist:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def configuration(self):
        """Message field 'configuration'."""
        return self._configuration

    @configuration.setter
    def configuration(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'configuration' field must be of type 'str'"
        self._configuration = value

    @property
    def baudrate(self):
        """Message field 'baudrate'."""
        return self._baudrate

    @baudrate.setter
    def baudrate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'baudrate' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'baudrate' field must be an unsigned integer in [0, 4294967295]"
        self._baudrate = value

    @property
    def port_name(self):
        """Message field 'port_name'."""
        return self._port_name

    @port_name.setter
    def port_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'port_name' field must be of type 'str'"
        self._port_name = value

    @property
    def rtcm_refresh_dist(self):
        """Message field 'rtcm_refresh_dist'."""
        return self._rtcm_refresh_dist

    @rtcm_refresh_dist.setter
    def rtcm_refresh_dist(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rtcm_refresh_dist' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'rtcm_refresh_dist' field must be an unsigned integer in [0, 65535]"
        self._rtcm_refresh_dist = value
