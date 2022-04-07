# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xsens_msgs:msg/StaSW.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StaSW(type):
    """Metaclass of message 'StaSW'."""

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
                'xsens_msgs.msg.StaSW')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sta_sw
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sta_sw
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sta_sw
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sta_sw
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sta_sw

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StaSW(metaclass=Metaclass_StaSW):
    """Message class 'StaSW'."""

    __slots__ = [
        '_xsens_status',
        '_filter_valid',
        '_gnss_fix',
        '_clock_sync',
        '_sync_in',
        '_sync_out',
        '_filter_mode',
        '_rtk_status',
    ]

    _fields_and_field_types = {
        'xsens_status': 'string',
        'filter_valid': 'string',
        'gnss_fix': 'string',
        'clock_sync': 'string',
        'sync_in': 'string',
        'sync_out': 'string',
        'filter_mode': 'string',
        'rtk_status': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.xsens_status = kwargs.get('xsens_status', str())
        self.filter_valid = kwargs.get('filter_valid', str())
        self.gnss_fix = kwargs.get('gnss_fix', str())
        self.clock_sync = kwargs.get('clock_sync', str())
        self.sync_in = kwargs.get('sync_in', str())
        self.sync_out = kwargs.get('sync_out', str())
        self.filter_mode = kwargs.get('filter_mode', str())
        self.rtk_status = kwargs.get('rtk_status', str())

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
        if self.xsens_status != other.xsens_status:
            return False
        if self.filter_valid != other.filter_valid:
            return False
        if self.gnss_fix != other.gnss_fix:
            return False
        if self.clock_sync != other.clock_sync:
            return False
        if self.sync_in != other.sync_in:
            return False
        if self.sync_out != other.sync_out:
            return False
        if self.filter_mode != other.filter_mode:
            return False
        if self.rtk_status != other.rtk_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def xsens_status(self):
        """Message field 'xsens_status'."""
        return self._xsens_status

    @xsens_status.setter
    def xsens_status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'xsens_status' field must be of type 'str'"
        self._xsens_status = value

    @property
    def filter_valid(self):
        """Message field 'filter_valid'."""
        return self._filter_valid

    @filter_valid.setter
    def filter_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'filter_valid' field must be of type 'str'"
        self._filter_valid = value

    @property
    def gnss_fix(self):
        """Message field 'gnss_fix'."""
        return self._gnss_fix

    @gnss_fix.setter
    def gnss_fix(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'gnss_fix' field must be of type 'str'"
        self._gnss_fix = value

    @property
    def clock_sync(self):
        """Message field 'clock_sync'."""
        return self._clock_sync

    @clock_sync.setter
    def clock_sync(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'clock_sync' field must be of type 'str'"
        self._clock_sync = value

    @property
    def sync_in(self):
        """Message field 'sync_in'."""
        return self._sync_in

    @sync_in.setter
    def sync_in(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sync_in' field must be of type 'str'"
        self._sync_in = value

    @property
    def sync_out(self):
        """Message field 'sync_out'."""
        return self._sync_out

    @sync_out.setter
    def sync_out(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'sync_out' field must be of type 'str'"
        self._sync_out = value

    @property
    def filter_mode(self):
        """Message field 'filter_mode'."""
        return self._filter_mode

    @filter_mode.setter
    def filter_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'filter_mode' field must be of type 'str'"
        self._filter_mode = value

    @property
    def rtk_status(self):
        """Message field 'rtk_status'."""
        return self._rtk_status

    @rtk_status.setter
    def rtk_status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'rtk_status' field must be of type 'str'"
        self._rtk_status = value
