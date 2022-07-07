# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/ConfigCam.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConfigCam(type):
    """Metaclass of message 'ConfigCam'."""

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
                'xsens_msgs.msg.ConfigCam')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__config_cam
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__config_cam
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__config_cam
            cls._TYPE_SUPPORT = module.type_support_msg__msg__config_cam
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__config_cam

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConfigCam(metaclass=Metaclass_ConfigCam):
    """Message class 'ConfigCam'."""

    __slots__ = [
        '_height',
        '_width',
        '_framerate',
        '_save_file',
    ]

    _fields_and_field_types = {
        'height': 'int32',
        'width': 'int32',
        'framerate': 'int32',
        'save_file': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.height = kwargs.get('height', int())
        self.width = kwargs.get('width', int())
        self.framerate = kwargs.get('framerate', int())
        self.save_file = kwargs.get('save_file', str())

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
        if self.height != other.height:
            return False
        if self.width != other.width:
            return False
        if self.framerate != other.framerate:
            return False
        if self.save_file != other.save_file:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'height' field must be an integer in [-2147483648, 2147483647]"
        self._height = value

    @property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'width' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'width' field must be an integer in [-2147483648, 2147483647]"
        self._width = value

    @property
    def framerate(self):
        """Message field 'framerate'."""
        return self._framerate

    @framerate.setter
    def framerate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'framerate' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'framerate' field must be an integer in [-2147483648, 2147483647]"
        self._framerate = value

    @property
    def save_file(self):
        """Message field 'save_file'."""
        return self._save_file

    @save_file.setter
    def save_file(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'save_file' field must be of type 'str'"
        self._save_file = value